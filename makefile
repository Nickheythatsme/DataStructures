#Compiler flags
CC = g++
CFLAGS = -Wall -g -std=c++11
OUT = -c -o

#PATHS
STACK = stack
23tree = two_three_tree

#Objs/Targets
OBJS = stack.o 23tree.o

all: $(OBJS)


#MAKING OBJECTS
stack.o: $(STACK)/main.cpp
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

23tree.o: $(23tree)/main.cpp
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
