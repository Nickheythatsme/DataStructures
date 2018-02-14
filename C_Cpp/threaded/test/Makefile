#Nicholas Grout
.PHONY: clean
CC=g++
CFLAGS= -pthread -g -std=c++14
 
OBJS= main.o
TARGET= test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main.o: main.cpp 
	$(CC) $< $(CFLAGS) -c -o $@


clean:
	rm -f *.o $(TARGET)
