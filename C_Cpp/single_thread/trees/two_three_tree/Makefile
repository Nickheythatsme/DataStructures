#Nicholas Grout
.PHONY: clean
CC=g++
CFLAGS= -g -std=c++14
 
OBJS= main.o
DEPS= two_three_node.cpp two_three_tree.cpp two_three_tree.h 
TARGET= two_three_tree

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main.o: main.cpp $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@


clean:
	rm -f *.o $(TARGET)
