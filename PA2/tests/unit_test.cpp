#include "unit_test.hpp"

int main() {
    runAllTests();
    return results.failed > 0 ? 1 : 0;
}