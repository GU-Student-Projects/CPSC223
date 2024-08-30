#ifndef UTILITIES_HPP
#define UTILITES_HPP
#endif

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <limits>
#include <thread>
#include <iomanip>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

// Utility to clear terminal screen
void clearScreen();
// Utility to clear cin input
void clearInputBuffer() ;
// Utility to print text 1 character at a time
void warGamesText(const std::string&, int);
// Utility to validate input
int getValidInteger(const std::string& prompt);
// Utility to lower characters in a string
std::string toLower(const std::string& str);