# Define the directories for source files
SRC_DIRS = . ./modules ./modules/utils

# Find all .cpp files in the specified directories
SRCS = $(wildcard $(foreach dir, $(SRC_DIRS), $(dir)/*.cpp))

# Target
all: Tree_Shadow

# Build and run the executable
Tree_Shadow: $(SRCS)
	@g++ -g -Wall -std=c++11 $(SRCS) -o outputExecutable
	@./outputExecutable
	@rm ./outputExecutable
