#include "unit_test.hpp"

TestResults results;

void TestResults::printSummary() {
        std::cout << "\nTest Summary:\n";
        std::cout << "Passed: " << passed << "\n";
        std::cout << "Failed: " << failed << "\n";
        std::cout << "Total:  " << (passed + failed) << "\n";
    }

// Run all tests
void runAllTests() {
    std::cout << "Running tests...\n\n";
    
    testWaterBodyCreation();
    testDamCreation();
    testWatershedStructure();
    testJsonSerialization();
    testJsonDeserialization();
    
    results.printSummary();
}