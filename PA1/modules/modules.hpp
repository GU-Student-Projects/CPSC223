#ifndef MODULES_HPP
#define MODULES_HPP
#endif

#include "./utils/linked_list.hpp"
#include "./utils/utilities.hpp"
#include <fstream>

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