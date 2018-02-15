#Nicholas Grout
.PHONY: clean
CC=g++
CFLAGS= -pthread -g -std=c++98 -Wall
 
OBJS= main.o X.o
TARGET= test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main.o: main.cpp 
	$(CC) $< $(CFLAGS) -c -o $@

X.o: X.cpp X.h
	$(CC) $< $(CFLAGS) -c -o $@


clean:
	rm -f *.o $(TARGET)
