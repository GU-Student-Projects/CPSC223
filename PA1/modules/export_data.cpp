/*
Name: Gabe DiMartino
Class: CPSC223, Fall 2024
Date: August 28, 2024
Programming Assignment: Project 1
Description: This cpp contains the functions for the input mode of the application
*/

#include "modules.hpp"

     /*************************************************************
    * Function: exportVectorOfLinkedLists()
    * Date Created: 8/28/24
    * Date Last Modified: 8/28/24
    * Description: Takes the vector of linked list and generates
    * a dat file.
    * Input parameters: Vector of Linked List, String
    * Returns: DAT file
    *************************************************************/

void exportVectorOfLinkedLists(const std::vector<StreetLinkedList>& streetLists, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open()) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return;
    }

    size_t vectorSize = streetLists.size();
    outFile.write(reinterpret_cast<const char*>(&vectorSize), sizeof(vectorSize));

    for (const auto& list : streetLists) {
        size_t nodeCount = list.findSize();
        outFile.write(reinterpret_cast<const char*>(&nodeCount), sizeof(nodeCount));

        size_t streetNameLength = list.streetName.size();
        outFile.write(reinterpret_cast<const char*>(&streetNameLength), sizeof(streetNameLength));
        outFile.write(list.streetName.c_str(), streetNameLength);

        Node* curr = list.head;
        while (curr != nullptr) {
            size_t approachingStreetLength = curr->approachingStreet.size();
            outFile.write(reinterpret_cast<const char*>(&approachingStreetLength), sizeof(approachingStreetLength));
            outFile.write(curr->approachingStreet.c_str(), approachingStreetLength);

            size_t leavingStreetLength = curr->leavingStreet.size();
            outFile.write(reinterpret_cast<const char*>(&leavingStreetLength), sizeof(leavingStreetLength));
            outFile.write(curr->leavingStreet.c_str(), leavingStreetLength);

            size_t treesPerBlockSize = curr->treesPerBlock.size();
            outFile.write(reinterpret_cast<const char*>(&treesPerBlockSize), sizeof(treesPerBlockSize));

            for (const auto& data : curr->treesPerBlock) {
                outFile.write(reinterpret_cast<const char*>(&data.westDistance), sizeof(data.westDistance));
                outFile.write(reinterpret_cast<const char*>(&data.eastDistance), sizeof(data.eastDistance));

                size_t treeTypeLength = data.treeType.size();
                outFile.write(reinterpret_cast<const char*>(&treeTypeLength), sizeof(treeTypeLength));
                outFile.write(data.treeType.c_str(), treeTypeLength);
            }

            curr = curr->next;
        }

    }

    outFile.close();
    warGamesText("EXPORTED VECTOR OF LINKED LISTS TO: " + filename, 50);
}

     /*************************************************************
    * Function: exportToTextFile()
    * Date Created: 8/27/24
    * Date Last Modified: 8/27/24
    * Description: Takes the vector of linked list and generates
    * text file report
    * Input parameters: Vector of Linked List, String
    * Returns: Text File
    *************************************************************/

void exportToTextFile(const std::vector<StreetLinkedList>& lists, const std::string& filename) {
        std::ofstream outFile(filename);

        if (!outFile) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        for (const auto& streetList : lists) {
            outFile << "Street: " << streetList.streetName << "\n";

            Node* current = streetList.head;
            int blockCount = 1;
            while (current != nullptr) {
                outFile << "Block " << blockCount << ":\n";
                outFile << "  Approaching Street: " << current->approachingStreet << "\n";
                outFile << "  Leaving Street: " << current->leavingStreet << "\n";
                outFile << "  Trees:\n";

                for (const auto& tree : current->treesPerBlock) {
                    outFile << "    Tree Type: " << tree.treeType << ", East Distance: " << tree.eastDistance << ", West Distance: " << tree.westDistance << "\n";
                }

                outFile << "\n";
                current = current->next;
                ++blockCount;
            }

            outFile << "----------------------------------------\n\n";
        }

        outFile.close();
    }