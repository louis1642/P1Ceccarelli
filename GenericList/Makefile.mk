CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = Node.h LinkedList.h LinkedList.cpp
OBJ = testGenericList.o

%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)
testGenericList: $(OBJ)
	$(CC) -o $@ $^