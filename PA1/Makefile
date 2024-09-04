# Directories for source files
SRC_DIRS = . ./modules ./modules/utils

# Find all .cpp files in the specified directories
SRCS = $(wildcard $(foreach dir, $(SRC_DIRS), $(dir)/*.cpp))

# Default target
all: Tree_Shadow

# Build and run the executable
Tree_Shadow: $(SRCS)
	@g++ -g -Wall -std=c++11 $(SRCS) -o outputExecutable
	@./outputExecutable
	@rm ./outputExecutable

# Debug target for running gdb and memory analysis
debug: $(SRCS)
	@g++ -g -Wall -std=c++11 $(SRCS) -o outputExecutable
	@echo "Running gdb for debugging..."
	@valgrind --vgdb=yes --vgdb-error=0 ./outputExecutable
	@gdb -q ./outputExecutable

# Clean target to remove generated files
clean:
	@rm -f outputExecutable

