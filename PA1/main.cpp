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
    std::string fileName;
    std::vector<StreetLinkedList> streetData;
    choice = mainMenu();

    if (2 == choice){        
        clearScreen();
        warGamesText("ENTERING DATA EXPLORATION MODE.",50);
        
        std::cout << "\nINPUT FILE: ";
        std::cin >> fileName;
        importVectorOfLinkedLists(streetData, fileName);
        explorationMode(streetData);

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
    std::string fileName;
    std::cout << "\nOUTPUT FILE NAME: ";
    std::cin >> fileName;
    exportVectorOfLinkedLists(streetData, "results/"+fileName+".dat");

    return 0;
    }
}
