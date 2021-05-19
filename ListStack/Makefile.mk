CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Node.h LinkedList.h LinkedList.cpp LStack.h
OBJ = Driver.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
Driver: $(OBJ)
	$(CC) -o $@ $^