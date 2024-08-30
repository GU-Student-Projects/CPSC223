/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 27, 2024
Programming Assignment: Project 1
Description: This cpp contains all of the definitions for the Doubly Linked List
*/

#include "linked_list.hpp"

// Constructor
StreetLinkedList::StreetLinkedList(const std::string& street)
    // Null pointer for head and tail. StreetName for labeling the list.
    : head(nullptr), tail(nullptr), streetName(street) {}

// Destructor
StreetLinkedList::~StreetLinkedList() {
    Node* current = head;
    // Go through each node and delete deconstruct.
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Copy Constructor
StreetLinkedList::StreetLinkedList(const StreetLinkedList& other)
    : head(nullptr), tail(nullptr), streetName(other.streetName) {
    Node* current = other.head;
    while (current != nullptr) {
        Node* newNode = new Node(*current);
        this->append(*newNode);
        current = current->next;
    }
}

// Copy Assignment Operator
StreetLinkedList& StreetLinkedList::operator=(const StreetLinkedList& other) {
    if (this == &other) {
        return *this;
    }

    // Clear the existing list
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;

    // Copy the streetName attribute
    streetName = other.streetName;

    // Copy the list
    current = other.head;
    while (current != nullptr) {
        Node* newNode = new Node(*current);
        this->append(*newNode);
        current = current->next;
    }
    
    return *this;
}

     /*************************************************************
    * Function: append()
    * Date Created: 8/27/24
    * Date Last Modified: 8/27/24
    * Description: Add node to linked list
    * Input parameters: None
    * Returns: CLI
    *************************************************************/


void StreetLinkedList::append(Node& newNode) {
    Node* newNodePtr = new Node(newNode);
    // If the list is empty, add new.
    if (head == nullptr) {
        head = tail = newNodePtr;
    // Else Append to the end
    } else {
        tail->next = newNodePtr;
        newNodePtr->prev = tail;
        tail = newNodePtr;
    }
}

     /*************************************************************
    * Function: printList()
    * Date Created: 8/27/24
    * Date Last Modified: 8/27/24
    * Description: Visualizes Linked List data
    * Input parameters: None
    * Returns: CLI
    *************************************************************/

void StreetLinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "There are " << current->treesPerBlock.size() << " trees, on the city block between " << streetName << " and cross streets: " << current->approachingStreet << " and " << current->leavingStreet << ".\n";
        for (const auto& tree : current->treesPerBlock) {
            std::cout << "  Tree Type: " << tree.treeType << ", Shadow Distance: " << tree.shadowDistance << " meter(s) \n";
        }
        current = current->next;
    }
}

int StreetLinkedList::findSize() const {
    int size = 0;
    Node* curr = head;
    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }
    return size;
}

void StreetLinkedList::insertNode(Node& newNode, int position) {
    Node* newNodePtr = new Node(newNode);

    if (position == 0) {
        if (head == nullptr) {
            head = tail = newNodePtr;
        } else {
            newNodePtr->next = head;
            head->prev = newNodePtr;
            head = newNodePtr;
        }
        return;
    }

    Node* current = head;
    int i = 0;
    while (current != nullptr && i < position - 1) {
        current = current->next;
        i++;
    }

    if (current == nullptr) {
        append(newNode);
    } else if (current->next == nullptr) {
        current->next = newNodePtr;
        newNodePtr->prev = current;
        tail = newNodePtr;
    } else {
        newNodePtr->next = current->next;
        newNodePtr->prev = current;
        current->next->prev = newNodePtr;
        current->next = newNodePtr;
    }
}

void StreetLinkedList::deleteNode(const std::string& approachingStreet, const std::string& leavingStreet) {
    Node* current = head;

    while (current != nullptr) {
        if (current->approachingStreet == approachingStreet && current->leavingStreet == leavingStreet) {
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else {
                current->prev->next = current->next;
            }

            if (current == tail) {
                tail = current->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }

            delete current;
            return;
        }
        current = current->next;
    }
    std::cout << "Node not found.\n";
}

Node* StreetLinkedList::searchNode(const std::string& approachingStreet, const std::string& leavingStreet) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->approachingStreet == approachingStreet && current->leavingStreet == leavingStreet) {
            return current;
        }
        current = current->next;
    }

    std::cout << "Node not found.\n";
    return nullptr;
}
