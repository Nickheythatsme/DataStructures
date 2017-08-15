#Compiler flags
CC = g++
CFLAGS = -Wall -g -std=c++11
OUT = -c -o


ifeq ($(shell uname -s),Darwin)
	CC = clang++
	CFLAGS += -O0
endif

#PATHS
STACK = stack
23tree = two_three_tree

#Objs/Targets
OBJS = stack.o 23tree.o

all: $(OBJS)
	@echo $(CC)


#MAKING OBJECTS
stack.o: $(STACK)/main.cpp $(STACK)/*
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

23tree.o: $(23tree)/main.cpp $(23tree)/*
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
	@rm -f results.txt
