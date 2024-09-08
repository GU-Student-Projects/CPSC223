# Directories for source files
SRC_DIRS = . ./modules ./modules/utils
TEST_DIRS = ./tests ./modules ./modules/utils

# Find all .cpp files in the specified directories, but not in the root
SRCS = $(wildcard $(foreach dir, $(SRC_DIRS), $(dir)/*.cpp))
TEST_SRCS = $(wildcard $(foreach dir, $(TEST_DIRS), $(dir)/*.cpp))

# Default target: build and run main.cpp from modules
all: main

main: $(SRCS)
	@g++ -g -Wall -std=c++11 $(SRCS) -o outputExecutable
	@./outputExecutable
	@rm ./outputExecutable

# Target for building and running tests, including the linked_list.hpp
test: $(TEST_SRCS)
	@g++ -g -Wall -std=c++11 -I./modules/utils $(TEST_SRCS) -o testExecutable
	@./testExecutable
	@rm ./testExecutable

# Debug target for running gdb and memory analysis on main.cpp
debug: $(SRCS)
	@g++ -g -Wall -std=c++11 $(SRCS) -o outputExecutable
	@echo "Running gdb for debugging..."
	@valgrind --vgdb=yes --vgdb-error=0 ./outputExecutable
	@gdb -q ./outputExecutable

# Clean target to remove generated files
clean:
	@rm -f outputExecutable testExecutable
