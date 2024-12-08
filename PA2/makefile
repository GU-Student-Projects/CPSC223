# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++11

# Check operating system for includes
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS specific
    INCLUDES = -I. -I/usr/local/include
else
    # Linux specific
    INCLUDES = -I. -I/usr/include
endif

# Source files
MAIN_SRCS = watershed.cpp main.cpp
TEST_SRCS = watershed.cpp test/tests.cpp

# Default target: build main program
all: watershed

# Build main program
watershed: $(MAIN_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(MAIN_SRCS) -o watershed

# Build and run tests
test: $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_SRCS) -o test_watershed
	./test_watershed
	@rm test_watershed

# Clean target
clean:
	rm -f watershed test_watershed

# Run both main build and tests
check: all test

# Help target for installation instructions
help:
	@echo "Before building, ensure nlohmann/json is installed:"
	@echo ""
	@echo "Ubuntu/Debian:"
	@echo "    sudo apt-get install nlohmann-json3-dev"
	@echo ""
	@echo "macOS:"
	@echo "    brew install nlohmann-json"
	@echo ""
	@echo "Manual installation:"
	@echo "    wget https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp"
	@echo "    sudo mkdir -p /usr/local/include/nlohmann"
	@echo "    sudo mv json.hpp /usr/local/include/nlohmann/"

.PHONY: all test clean check help