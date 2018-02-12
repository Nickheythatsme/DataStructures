#Nicholas Grout
.PHONY: clean
CC=g++
CFLAGS= -pthread -g -std=c++14
 
OBJS= main.o
TARGET= queue

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main.o: main.cpp queue.h queue.cpp
	$(CC) $< $(CFLAGS) -c -o $@


clean:
	rm -f *.o $(TARGET)
