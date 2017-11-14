#Compiler flags
CC = g++
CFLAGS = -Wall -g -std=c++11
OUT = -c -o

#Objs/Targets
OBJS = main.o 
DEPS = stack.h stack.cpp
TARGET = stack

all: $(TARGET)


#MAKING TARGET
$(TARGET): $(OBJS)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $^ -o $@

#MAKING OBJECTS
main.o: main.cpp $(DEPS)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@


clean:
	@rm -rf $(BIN)
	@rm -f $(TARGET)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
