#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#endif

#include <iostream>
#include <string>
#include <vector>

// Data structure to store information about each tree
struct Data {
    int shadowDistance;
    std::string treeType;

    Data(int sd, const std::string& tt) : shadowDistance(sd), treeType(tt) {}
};

// Node structure for the linked list
struct Node {
    std::vector<Data> treesPerBlock;
    Node* prev;
    Node* next;
    std::string approachingStreet;
    std::string leavingStreet;

    Node(int size, const std::string& street1, const std::string& street2)
        : prev(nullptr), next(nullptr), approachingStreet(street1), leavingStreet(street2) {
        treesPerBlock.reserve(size);
    }
};

// Doubly Linked list class for streets
class StreetLinkedList {
public:
    Node* head;
    Node* tail;
    std::string streetName;

    // Constructor
    StreetLinkedList(const std::string& street);

    // Destructor
    ~StreetLinkedList();

    // Copy Constructor
    StreetLinkedList(const StreetLinkedList& other);

    // Copy Assignment Operator
    StreetLinkedList& operator=(const StreetLinkedList& other);

    // Add node to end of List
    void append(Node& newNode);

    // Print List
    void printList() const;

    // Find size of Linked List
    int findSize() const;

    // Insert a node at integer position
    void insertNode(Node& newNode, int position);

    // Delete node with given approaching street and leaving street
    void deleteNode(const std::string& approachingStreet, const std::string& leavingStreet);

    // Find node based on cross streets
    Node* searchNode(const std::string& approachingStreet, const std::string& leavingStreet) const;
};