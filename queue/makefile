#Compiler flags
CC = g++
CFLAGS = -Wall -g -std=c++11
OUT = -c -o

#PATHS
BIN=bin

#Objs/Targets
OBJS = main.o 
TARGET = queue

all: $(TARGET)


#MAKING TARGET
queue: $(addprefix $(BIN)/,$(OBJS))
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $^ -o $@

#MAKING OBJECTS
$(BIN)/main.o: main.cpp queue.cpp queue.h
	@mkdir -p $(BIN)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

clean:
	@rm -rf $(BIN)
	@rm -f $(TARGET)
	@rm -f *.swp
	@rm -f *.o
	@rm -rf *.dSYM
