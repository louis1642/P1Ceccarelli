CC=g++
CFLAGS=-std=c++11
DEPS=Time.h
OBJ= Time.o main.o

%.0: %.cpp $(DEPS)
	%(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)