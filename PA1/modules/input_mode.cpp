/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 27, 2024
Programming Assignment: Project 1
Description: This cpp contains the functions for the input mode of the application
*/

#include "modules.hpp"


     /*************************************************************
    * Function: inputMode()
    * Date Created: 8/27/24
    * Date Last Modified: 8/27/24
    * Description: Takes user input on shaded trees for each block
    * to generate a report
    * Input parameters: None
    * Returns: Vector of Linked Lists
    *************************************************************/

std::vector<StreetLinkedList> inputMode() {
    std::vector<StreetLinkedList> processedData;
    bool finishedStreets = false;

    while (!finishedStreets) {
        std::string longitudinalStreet;
        std::cout << "\nLONGITUDINAL STREET (EAST/WEST): ";
        std::cin >> longitudinalStreet;

        if (toLower(longitudinalStreet) == "end") {
            std::cout << "SAVING DATA AND EXITING\n";
            finishedStreets = true;
            continue;
        }

        StreetLinkedList street(longitudinalStreet);
        bool finishedCrossStreets = false;

        warGamesText("\nFOR EACH BLOCK, INPUT THE APPROACHING STREET, AND PASSING STREET. TO EXIT, SIMPLY TYPE \"END\"", 50);

        while (!finishedCrossStreets) {
            std::string approachingStreet, passingStreet;
            std::cout << "\nAPPROACHING: ";
            std::cin >> approachingStreet;
            if (toLower(approachingStreet) == "end") {
                std::cout << "\nSAVING DATA AND EXITING\n";
                finishedCrossStreets = true;
                break;
            }

            std::cout << "PASSING: ";
            std::cin >> passingStreet;
            if (toLower(passingStreet) == "end") {
                std::cout << "SAVING DATA AND EXITING\n";
                finishedCrossStreets = true;
                break;
            }

            int numberOfTrees = getValidInteger("HOW MANY TREES WERE ON THIS BLOCK? ");

            if (numberOfTrees > 1000) {
                std::cout << "Number of trees is too high. Please enter a number up to 1000.\n";
                numberOfTrees = getValidInteger("HOW MANY TREES WERE ON THIS BLOCK? ");
            }

            else if ( numberOfTrees == 0) {
                Node cityBlock(numberOfTrees, approachingStreet, passingStreet);
                street.append(cityBlock);

            }

            else {

            Node cityBlock(numberOfTrees, approachingStreet, passingStreet);

            for (int i = 0; i < numberOfTrees; i++) {
                int shadowDistance = getValidInteger("SHADOW DISTANCE FOR TREE " + std::to_string(i + 1) + " OUT OF " + std::to_string(numberOfTrees) + " (Meters): ");
                std::string treeType;
                std::cout << "TREE TYPE FOR TREE " + std::to_string(i + 1) + " OUT OF " + std::to_string(numberOfTrees) + ": ";
                std::cin >> treeType;

                cityBlock.treesPerBlock.emplace_back(shadowDistance, treeType);
            }

            street.append(cityBlock);
            }
        }

        processedData.push_back(street);

    }

    return processedData;
}