/*
Name: Group 12
Class: CPSC223, Fall 2024
Date: December 7, 2024
Programming Assignment: Project 2
Description: This cpp runs the program
*/

#include "header.hpp"
#include <iostream>
#include <fstream>

int main() {
    WatershedTree watershed;
    char choice;
    
    do {
        std::cout << "\nColumbia River Watershed Management\n";
        std::cout << "1. Add water body\n";
        std::cout << "2. Navigate watershed\n";
        std::cout << "3. Display entire watershed\n";
        std::cout << "4. Save to file\n";
        std::cout << "5. Load from file\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case '1':
                watershed.addWaterBody();
                break;
            case '2':
                watershed.navigate();
                break;
            case '3':
                watershed.displayTree();
                break;
            case '4': {
                std::string filename;
                std::cout << "Enter filename to save (results/): ";
                std::getline(std::cin, filename);
                watershed.saveToFile(filename);
                break;
            }
            case '5': {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::getline(std::cin, filename);
                watershed.loadFromFile(filename);
                break;
            }
            case '6':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != '6');
    
    return 0;
}