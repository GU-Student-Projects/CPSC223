// main.cpp
#include "header.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3 || (std::string(argv[1]) != "--load" && std::string(argv[1]) != "--save")) {
        return 1;
    }

    WatershedTree watershed;
    std::string command = argv[1];
    std::string filename = argv[2];

    if (command == "--load") {
        return watershed.loadFromFile(filename) ? 0 : 1;
    } else { // --save
        return watershed.saveToFile(filename) ? 0 : 1;
    }
}