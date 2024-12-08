// header.hpp
#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct Dam {
    std::string name;
    int yearBuilt;
    double capacity;
    
    json to_json() const;
    void from_json(const json& j);
};

class WaterBody {
public:
    std::string name;
    std::string type;
    double length;
    double basinSize;
    double averageDischarge;
    std::vector<Dam> dams;
    WaterBody* left;
    WaterBody* right;
    WaterBody* parent;
    
    WaterBody();
    WaterBody(const WaterBody& other);
    ~WaterBody();
    
    json to_json() const;
    void from_json(const json& j);
    void setParentPointers(WaterBody* parentNode);
};

class WatershedTree {
private:
    WaterBody* root;
    void deleteTree(WaterBody* node);
    
public:
    WatershedTree();
    ~WatershedTree();
    
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
};

#endif