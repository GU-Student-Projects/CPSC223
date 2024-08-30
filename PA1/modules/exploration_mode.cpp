/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 27, 2024
Programming Assignment: Project 1
Description: This cpp contains the functions for the exploration mode of the application
*/

#include "modules.hpp"

     /*************************************************************
    * Function: explorationMode()
    * Date Created: 8/28/24
    * Date Last Modified: 8/28/24
    * Description: CLI ability to traverse both linked lists, and nodes.
    * Input parameters: Vector of Linked Lists
    * Returns: None
    *************************************************************/

void explorationMode(std::vector<StreetLinkedList> streetData) {
    std::vector<std::string> streets;

    for (const auto& list : streetData) {
        streets.push_back(list.streetName);
    }

    streets.push_back("All");

    std::string menu = "|----------- Main Menu -----------|\n";

    for (const auto& street : streets) {
        
    }







}