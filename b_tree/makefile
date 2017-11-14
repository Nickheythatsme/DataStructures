#Compiler flags
CC = g++
CFLAGS = -std=gnu++0x -Wall -g3
OUT = -c -o

#Objs/Targets
OBJS = test_main.o
DEPS = node.cpp node.h data_holder.cpp data_holder.h
TARGET = b_tree

#MAKING OBJECTS
$(TARGET): $(OBJS)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $(OBJS) -o $@

test_main.o: test_main.cpp $(DEPS)
	@echo "compiling: " $@
	@$(CC) $(CFLAGS) $< $(OUT) $@

clean:
	@rm $(TARGET)
	@rm -f *.swp *.o
	@rm -rf *.dSYM
