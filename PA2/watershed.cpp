// implementation.cpp
#include "header.hpp"
#include <fstream>
#include <iostream>

json Dam::to_json() const {
    return {
        {"name", name},
        {"yearBuilt", yearBuilt},
        {"capacity", capacity}
    };
}

void Dam::from_json(const json& j) {
    name = j["name"];
    yearBuilt = j["yearBuilt"];
    capacity = j["capacity"];
}

WaterBody::WaterBody() : 
    name(""),
    type(""),
    length(0),
    basinSize(0),
    averageDischarge(0),
    left(nullptr),
    right(nullptr),
    parent(nullptr) {}

WaterBody::WaterBody(const WaterBody& other) :
    name(other.name),
    type(other.type),
    length(other.length),
    basinSize(other.basinSize),
    averageDischarge(other.averageDischarge),
    dams(other.dams),
    left(nullptr),
    right(nullptr),
    parent(nullptr) {}

WaterBody::~WaterBody() {}

json WaterBody::to_json() const {
    json j = {
        {"name", name},
        {"type", type},
        {"length", length},
        {"basinSize", basinSize},
        {"averageDischarge", averageDischarge},
        {"dams", json::array()}
    };
    
    for (const auto& dam : dams) {
        j["dams"].push_back(dam.to_json());
    }
    
    if (left) {
        j["left"] = left->to_json();
    } else {
        j["left"] = json(nullptr);
    }
    
    if (right) {
        j["right"] = right->to_json();
    } else {
        j["right"] = json(nullptr);
    }
    
    return j;
}

void WaterBody::setParentPointers(WaterBody* parentNode) {
    parent = parentNode;
    if (left) left->setParentPointers(this);
    if (right) right->setParentPointers(this);
}

void WaterBody::from_json(const json& j) {
    name = j.at("name");
    type = j.at("type");
    length = j.at("length");
    basinSize = j.value("basinSize", 0.0);
    averageDischarge = j.value("averageDischarge", 0.0);
    
    dams.clear();
    if (j.contains("dams") && j["dams"].is_array()) {
        for (const auto& dam_json : j["dams"]) {
            Dam dam;
            dam.from_json(dam_json);
            dams.push_back(dam);
        }
    }
    
    left = nullptr;
    right = nullptr;
    
    if (j.contains("left") && !j["left"].is_null()) {
        left = new WaterBody();
        left->from_json(j["left"]);
        left->parent = this;
    }
    
    if (j.contains("right") && !j["right"].is_null()) {
        right = new WaterBody();
        right->from_json(j["right"]);
        right->parent = this;
    }
}

WatershedTree::WatershedTree() : root(nullptr) {}

WatershedTree::~WatershedTree() {
    deleteTree(root);
}

void WatershedTree::deleteTree(WaterBody* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

bool WatershedTree::loadFromFile(const std::string& filename) {
    std::string fullFilename = filename;
    if (fullFilename.substr(fullFilename.length() - 5) != ".json") {
        fullFilename += ".json";
    }
    
    std::ifstream file(fullFilename);
    if (!file.is_open()) {
        return false;
    }
    
    try {
        json j;
        file >> j;
        
        deleteTree(root);
        root = new WaterBody();
        root->from_json(j);
        root->setParentPointers(nullptr);
        
        file.close();
        return true;
    }
    catch (const std::exception&) {
        file.close();
        deleteTree(root);
        root = nullptr;
        return false;
    }
}

bool WatershedTree::saveToFile(const std::string& filename) const {
    if (!root) {
        return false;
    }
    
    std::string fullFilename = filename;
    if (fullFilename.substr(fullFilename.length() - 5) != ".json") {
        fullFilename += ".json";
    }
    
    std::ofstream file(fullFilename);
    if (!file.is_open()) {
        return false;
    }
    
    json j = root->to_json();
    file << j.dump(4);
    
    file.close();
    return true;
}

void WatershedTree::addWaterBody() {
    WaterBody* newBody = new WaterBody();
    
    std::cout << "Enter water body name: ";
    std::getline(std::cin, newBody->name);
    
    std::cout << "Enter type (river/stream): ";
    std::getline(std::cin, newBody->type);
    
    std::cout << "Enter length in kilometers: ";
    std::cin >> newBody->length;
    std::cin.ignore();

    std::cout << "Enter basin size in square kilometers (0 if unknown): ";
    std::cin >> newBody->basinSize;
    std::cin.ignore();

    std::cout << "Enter average discharge in cubic meters per second (0 if unknown): ";
    std::cin >> newBody->averageDischarge;
    std::cin.ignore();
    
    if (!root) {
        root = newBody;
        return;
    }
    
    WaterBody* current = root;
    while (true) {
        std::cout << "Add as left (1) or right (2) tributary of " << current->name << "? ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        
        if (choice == 1) {
            if (!current->left) {
                WaterBody* continuation = new WaterBody(*current);
                current->left = newBody;
                current->right = continuation;
                newBody->parent = current;
                continuation->parent = current;
                break;
            }
            current = current->left;
        } else {
            if (!current->right) {
                WaterBody* continuation = new WaterBody(*current);
                current->right = newBody;
                current->left = continuation;
                newBody->parent = current;
                continuation->parent = current;
                break;
            }
            current = current->right;
        }
    }
}