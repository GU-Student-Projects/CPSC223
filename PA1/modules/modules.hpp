#ifndef MODULES_HPP
#define MODULES_HPP
#endif

#include "./utils/linked_list.hpp"
#include "./utils/utilities.hpp"
#include <fstream>
#include <unordered_map>

// Simple struct to store node selection
struct BlockData {
    std::string approachingStreet;
    std::string passingStreet;
};

// Input data mode for tree shadow mapping
std::vector<StreetLinkedList> inputMode();

// Exports Vector of Doubly Linked Lists into a txt file
void exportToTextFile(const std::vector<StreetLinkedList>& lists, const std::string& filename);

// Exports Vector of Doubly Linked Lists into a dat file
void exportVectorOfLinkedLists(const std::vector<StreetLinkedList>& streetLists, const std::string& filename);

// Imports Vector of Doubly Linked List from dat file
void importVectorOfLinkedLists(std::vector<StreetLinkedList>& streetLists, const std::string& filename);

// Simple menu for deciding actions
int mainMenu();

// Explore all linked lists and their nodes
void explorationMode(std::vector<StreetLinkedList>& streetData);


// Select a specific block
void blockMenu(StreetLinkedList& list, std::vector<StreetLinkedList>& streetData);

// Explore specific linked list
void streetExploration(StreetLinkedList& list, std::vector<StreetLinkedList>& streetData, Node* current);