#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include "../header.hpp"

struct TestResults {
    int passed = 0;
    int failed = 0;
    
    void printSummary();
};

extern TestResults results;

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cout << "FAILED: " << message << " in " << __FILE__ << ":" << __LINE__ << "\n"; \
            results.failed++; \
            return; \
        } \
    } while (0)

void testWaterBodyCreation();
void testDamCreation();
void testWatershedStructure();
void testJsonSerialization();
void testJsonDeserialization();
void runAllTests();

#endif