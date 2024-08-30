/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 28, 2024
Programming Assignment: Project 1
Description: This cpp contains the functions for the input mode of the application
*/

#include "modules.hpp"

void importVectorOfLinkedLists(std::vector<StreetLinkedList>& streetLists, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Unable to open file for reading" << std::endl;
        return;
    }

    size_t vectorSize;
    inFile.read(reinterpret_cast<char*>(&vectorSize), sizeof(vectorSize));

    for (size_t i = 0; i < vectorSize; i++) {
        size_t nodeCount;
        inFile.read(reinterpret_cast<char*>(&nodeCount), sizeof(nodeCount));

        size_t streetNameLength;
        inFile.read(reinterpret_cast<char*>(&streetNameLength), sizeof(streetNameLength));
        std::string streetName(streetNameLength, '\0');
        inFile.read(&streetName[0], streetNameLength);

        StreetLinkedList street(streetName);

        for (size_t j = 0; j < nodeCount; j++) {
            size_t approachingStreetLength;
            inFile.read(reinterpret_cast<char*>(&approachingStreetLength), sizeof(approachingStreetLength));
            std::string approachingStreet(approachingStreetLength, '\0');
            inFile.read(&approachingStreet[0], approachingStreetLength);

            size_t leavingStreetLength;
            inFile.read(reinterpret_cast<char*>(&leavingStreetLength), sizeof(leavingStreetLength));
            std::string leavingStreet(leavingStreetLength, '\0');
            inFile.read(&leavingStreet[0], leavingStreetLength);

            size_t treesPerBlockSize;
            inFile.read(reinterpret_cast<char*>(&treesPerBlockSize), sizeof(treesPerBlockSize));

            Node newNode(treesPerBlockSize, approachingStreet, leavingStreet);

            for (size_t k = 0; k < treesPerBlockSize; k++) {
                int shadowDistance;
                inFile.read(reinterpret_cast<char*>(&shadowDistance), sizeof(shadowDistance));

                size_t treeTypeLength;
                inFile.read(reinterpret_cast<char*>(&treeTypeLength), sizeof(treeTypeLength));
                std::string treeType(treeTypeLength, '\0');
                inFile.read(&treeType[0], treeTypeLength);

                newNode.treesPerBlock.emplace_back(shadowDistance, treeType);
            }

            street.append(newNode);

        }

        streetLists.push_back(street);
    }

    inFile.close();
    warGamesText("IMPORTED VECTOR OF LINKED LISTS FROM:" + filename, 50);
}
