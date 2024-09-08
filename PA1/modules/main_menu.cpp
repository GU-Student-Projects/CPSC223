/*
Name: Group 12
Class: CPSC223, Fall 2024
Date: August 27, 2024
Programming Assignment: Project 1
Description: This cpp contains the functions for the main menu
*/

#include "modules.hpp"

     /*************************************************************
    * Function: mainMenu ()
    * Date Created: 11/30/23
    * Date Last Modified: 11/30/23
    * Description: Prints mainMenu selector
    * Input parameters: void
    * Returns: terminal output
    *************************************************************/

int mainMenu() {
    int choice;

    std::string menu = "|----------- Main Menu -----------|\n"
                       "  1. Input Mode\n"
                       "  2. Exploration Mode\n"
                       "  3. Exit\n";

    warGamesText(menu, 1);

    while (true) {
        choice = getValidInteger("SELECT 1, 2, OR 3: ");
        switch (choice) {
            case 1:
                warGamesText("Entering Input Mode", 10);
                std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
            case 2:
                warGamesText("Entering Exploration Mode", 10);
                std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
            case 3:
                warGamesText("Exiting...", 10);
                std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
            default:
                std::cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                continue;
        }

        break; // Exit the loop if a valid choice is made
    }

    return choice;
}