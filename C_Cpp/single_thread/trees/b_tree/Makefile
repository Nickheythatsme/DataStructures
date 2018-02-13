#Nicholas Grout
.PHONY: clean
CC=g++
CFLAGS= -g -std=c++14
 
OBJS= main.o test_O.cpp
DEPS= b_tree.cpp b_tree.h data_holder.cpp data_holder.h datum.cpp datum.h node.cpp node.h 
TARGET= B_TREE

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main.o: main.cpp $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@

test_O.o: test_O.o
	$(CC) $< $(CFLAGS) -c -o $@


clean:
	rm -f *.o $(TARGET)

