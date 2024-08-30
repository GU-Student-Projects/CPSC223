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

void explorationMode(std::vector<StreetLinkedList>& streetData) {
    std::unordered_map<std::string, std::string> menuMap;
    std::string choice;
    std::string menu = "|----------- Street Menu -----------|\n";

    for (size_t i = 0; i < streetData.size(); i++) {
        std::string indexStr = std::to_string(i + 1);
        std::string streetName = streetData[i].streetName;

        menu += indexStr + ". " + streetName + "\n";
        menuMap[indexStr] = streetName;
    }

    menu += std::to_string(streetData.size() + 1) + ". All\n";
    menuMap[std::to_string(streetData.size() + 1)] = "All";

    warGamesText(menu, 1);

    while (true) {
        std::cout << "SELECT A STREET: ";
        std::cin >> choice;

        if (menuMap.find(choice) != menuMap.end()) {
            std::string selectedStreet = menuMap[choice];
            warGamesText("YOU SELECTED: " + selectedStreet, 50);
            choice = selectedStreet;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    if (choice != "All") {
        for (auto& list : streetData) {
            if (list.streetName == choice) {
                streetExploration(list, streetData);
                break;
            }
        }
    } else {
        for (auto& street : streetData) {
            street.printList();
        }
    }

    warGamesText("EXPLORATION ENDED.", 50);
}

void streetExploration(StreetLinkedList& list, std::vector<StreetLinkedList>& streetData) {
    Node* current = list.head;

    while (true) {
        if (current != nullptr) {
            std::cout << "There are " << current->treesPerBlock.size() << " trees on the city block between " 
                      << current->approachingStreet << " and " << current->leavingStreet << ".\n";

            for (const auto& tree : current->treesPerBlock) {
                std::cout << "  Tree Type: " << tree.treeType 
                          << ", East Distance: " << tree.eastDistance
                          << " meter(s)"
                            << ", West Distance: " << tree.westDistance
                          << " meter(s)" << std::endl;
            }
        } else {
            std::cout << "The current block is empty or does not exist.\n";
        }

        std::cout << "Enter 'N' for next block, 'P' for previous block, 'TAIL' for end, 'HEAD' for beginning, 'C' to change street, or 'END' to quit: ";
        std::string input;
        std::cin >> input;

        std::string inputLower = toLower(input);

        if (inputLower == "n") {
            if (current != nullptr && current->next != nullptr) {
                current = current->next;
            } else {
                std::cout << "This is the last block. Can't move forward.\n \n";
            }
        } else if (inputLower == "p") {
            if (current != nullptr && current->prev != nullptr) {
                current = current->prev;
            } else {
                std::cout << "This is the first block. Can't move backward.\n \n";
            }
        } else if (inputLower == "tail") {
            if (current != nullptr) {
                while (current->next != nullptr) {
                    current = current->next;
                }
                std::cout << "Moved to the end of the street.\n \n";
            }
        } else if (inputLower == "head") {
            current = list.head;
            std::cout << "Moved to the beginning of the street.\n \n";
        } else if (inputLower == "c") {
            explorationMode(streetData);
            break;
        } else if (inputLower == "end") {
            break;
        } else {
            std::cout << "Invalid input. Please enter 'n', 'p', 'tail', 'head', 'c', or 'end'.\n \n";
        }
    }

}