#include "unit_test.hpp"

void testExportAndImportVectorOfLinkedLists() {
    StreetLinkedList list1("Sharp");
    Node node1(1, "Cincinnati", "Dakota");
    Node node2(2, "Dakota", "Standard");
    list1.append(node1);
    list1.append(node2);

    StreetLinkedList list2("Oak");
    Node node3(1, "Elm", "Birch");
    Node node4(2, "Birch", "Maple");
    list2.append(node3);
    list2.append(node4);

    std::vector<StreetLinkedList> streetLists = {list1, list2};
    std::string filename = "test_export.dat";

    exportVectorOfLinkedLists(streetLists, filename);

    std::vector<StreetLinkedList> importedStreetLists;
    importVectorOfLinkedLists(importedStreetLists, filename);

    assert(importedStreetLists.size() == streetLists.size());

    for (size_t i = 0; i < streetLists.size(); ++i) {
        const StreetLinkedList& originalList = streetLists[i];
        const StreetLinkedList& importedList = importedStreetLists[i];

        assert(originalList.findSize() == importedList.findSize());
        assert(originalList.streetName == importedList.streetName);

        Node* originalNode = originalList.head;
        Node* importedNode = importedList.head;

        while (originalNode != nullptr && importedNode != nullptr) {
            assert(originalNode->approachingStreet == importedNode->approachingStreet);
            assert(originalNode->leavingStreet == importedNode->leavingStreet);

            assert(originalNode->treesPerBlock.size() == importedNode->treesPerBlock.size());

            for (size_t j = 0; j < originalNode->treesPerBlock.size(); ++j) {
                assert(originalNode->treesPerBlock[j].westDistance == importedNode->treesPerBlock[j].westDistance);
                assert(originalNode->treesPerBlock[j].eastDistance == importedNode->treesPerBlock[j].eastDistance);
                assert(originalNode->treesPerBlock[j].treeType == importedNode->treesPerBlock[j].treeType);
            }

            originalNode = originalNode->next;
            importedNode = importedNode->next;
        }

        assert(originalNode == nullptr && importedNode == nullptr);
    }

    std::cout << "testExportAndImportVectorOfLinkedLists passed successfully!" << std::endl;
}
