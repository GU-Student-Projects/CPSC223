/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 27, 2024
Programming Assignment: Project 1
Description: This cpp runs the program
*/

#include "header.hpp"

int main() {
    int choice;
    std::vector<StreetLinkedList> streetData;
    choice = mainMenu();

    if (2 == choice){        
        clearScreen();
        warGamesText("ENTERING DATA EXPLORATION MODE.",50);
        importVectorOfLinkedLists(streetData, "output.dat");

        for (const auto& street : streetData) {
        street.printList();
        }

		return 0;
        }
	else if (3 == choice) { return 0;}
	else {
    
	clearScreen();
    warGamesText("ENTERING DATA INPUT MODE. TO EXIT, SIMPLY TYPE \"END\" ",50);
    streetData = inputMode();
    for (const auto& street : streetData) {
        street.printList();
    }

    // exportToTextFile(streetData, "street_data.txt");
    exportVectorOfLinkedLists(streetData, "output.dat");

    return 0;
    }
}
