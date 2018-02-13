#Nicholas Grout
.PHONY: clean
CC=g++
CFLAGS= -g -std=c++14
 
OBJS= main.o
DEPS= node.cpp node.h
TARGET= BST

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main.o: main.cpp $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@


clean:
	rm -f *.o $(TARGET)
