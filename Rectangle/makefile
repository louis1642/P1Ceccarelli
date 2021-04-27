CC=g++
CFLAGS=-std=c++11
DEPS=Point.h Rectangle.h
OBJ=Point.o Rectangle.o driver.o

%.o:%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
driver:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)