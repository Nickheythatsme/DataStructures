#Nicholas Grout
.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall

SORTING_DIR=./sorting_functions

OBJS= sort_test.o $(wildcard $(SORTING_DIR)/*.c)
TARGET= sorting

all: $(TARGET)

$(TARGET): $(OBJS) $(SORTING_OBJ)
	gcc $^ -o $@

sort_test.o: sort_test.c sort_test.h
	gcc $< -c -o $@

%.o: %.c
	gcc $< -c -o $@

clean:
	rm -f *.o $(TARGET) $(SORTING_DIR)/*.o
