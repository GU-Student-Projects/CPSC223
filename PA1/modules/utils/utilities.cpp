/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 27, 2024
Programming Assignment: Project 1
Description: This cpp contains all of the definitions of functions for general utilities
*/

#include "utilities.hpp"
     /*************************************************************
    * Function: toLower ()
    * Date Created: 8/27/24
    * Date Last Modified: 8/27/24
    * Description: transforms each character in a string (array)
    * to a lowercase character
    * Input parameters: Str
    * Returns: Str
    *************************************************************/

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}



     /*************************************************************
    * Function: clearScreen ()
    * Date Created: 9/2/23
    * Date Last Modified: 9/2/23
    * Description: Uses an if statement to determine what OS is uesed
    * then runs the system command to clear the terminal
    * Input parameters: System OS
    * Returns: Clear Screen
    * Pre: Correct library
    * Post: Clear Screen
    *************************************************************/

void clearScreen(){ //function to clear terminal
#ifdef _WIN32 //If OS is WIN32 run cls else use clear
    system("cls");
#else
    system("clear");
#endif
}

     /*************************************************************
    * Function: warGamesText ()
    * Date Created: 11/30/23
    * Date Last Modified: 11/30/23
    * Description: Prints characters with delay to mimick the
    * war games movie and terminal style
    * Input parameters: string and millisecond delay
    * Returns: terminal output
    *************************************************************/


void warGamesText(const std::string& text, int delayMS = 50) { //function to print characters one at a time
    for (char c : text) {
        std::cout << std::fixed << std::setprecision(2) << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMS));
    }
    std::cout << std::endl;
}

     /*************************************************************
    * Function: clearInputBuffer ()
    * Date Created: 11/30/23
    * Date Last Modified: 11/30/23
    * Description: utility to clear cin inputs
    * Input parameters: void
    * Returns: empty buffer
    *************************************************************/

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

     /*************************************************************
    * Function: getValidInteger ()
    * Date Created: 8/27/24
    * Date Last Modified: 8/27/24
    * Description: Input Validation for integer inputs
    * Input parameters: Str
    * Returns: terminal Int
    *************************************************************/
int getValidInteger(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            clearInputBuffer();
        } else {
            clearInputBuffer(); // Clear any remaining input
            return value;
        }
    }
}

