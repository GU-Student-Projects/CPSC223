#include "unit_test.hpp"

int main() {
    testAppend();
    testInsertNode();
    testDeleteNode();
    testSearchNode();
    testPrintList();
    testCopyConstructor();
    testCopyAssignmentOperator();
    testExportAndImportVectorOfLinkedLists();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}