/*
Name: Group 12
Class: CPSC223, Fall 2024
Date: September 7, 2024
Programming Assignment: Project 1
Description: This cpp runs all unit tests
*/

#include "unit_test.hpp"

int main() {
    testAppend();
    testInsertNode();
    testDeleteNode();
    testSearchNode();
    testPrintList();
    testCopyConstructor();
    testCopyAssignmentOperator();
    testExportAndImportVectorOfLinkedLists();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}