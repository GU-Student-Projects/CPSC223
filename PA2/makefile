# Directories for source files
SRC_DIRS = .
TEST_DIRS = ./tests

# Find all .cpp files in the specified directories, but not in the root
SRCS = $(wildcard $(foreach dir, $(SRC_DIRS), $(dir)/*.cpp))

MAIN_SRC = $(filter %main.cpp, $(SRCS))
OTHER_SRCS = $(filter-out %main.cpp, $(SRCS))
TEST_SRCS = $(wildcard $(foreach dir, $(TEST_DIRS), $(dir)/*.cpp)) $(OTHER_SRCS)

# Compiler flags
CXX = g++
CXXFLAGS = -g -Wall -std=c++11
INCLUDES = -I. -I/usr/local/include

# Check if we need to link against a separate json library
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS specific
    JSON_INCLUDES = -I/usr/local/include
else
    # Linux specific
    JSON_INCLUDES = -I/usr/include
endif

# Default target: build and run main.cpp
all: main

main: $(SRCS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(JSON_INCLUDES) $(SRCS) -o outputExecutable
	@./outputExecutable
	@rm ./outputExecutable

# Target for building and running tests
test: $(TEST_SRCS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(JSON_INCLUDES) $(TEST_SRCS) -o testExecutable
	@./testExecutable
	@rm ./testExecutable

# Debug target for running gdb and memory analysis
debug: $(SRCS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(JSON_INCLUDES) $(SRCS) -o outputExecutable
	@echo "Running gdb for debugging..."
	@valgrind --vgdb=yes --vgdb-error=0 ./outputExecutable
	@gdb -q ./outputExecutable

# Clean target to remove generated files
clean:
	@rm -f outputExecutable testExecutable

# Help target to show installation instructions
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