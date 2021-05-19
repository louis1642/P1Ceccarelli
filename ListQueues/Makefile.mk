CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = CNode.h CLinkedList.h CLinkedList.cpp Queue.h
OBJ = Driver.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)