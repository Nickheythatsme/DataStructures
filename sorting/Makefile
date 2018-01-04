#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall
OBJS= sort_test.o sorting_functions.o
TARGET= sorting

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc $^ -o $@

sorting_functions.o: sorting_functions.c
	gcc $< -c -o $@

sort_test.o: sort_test.c sort_test.h
	gcc $< -c -o $@

clean:
	rm -f *.o $(TARGET)
