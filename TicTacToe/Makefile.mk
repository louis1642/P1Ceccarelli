CFLAGS = -std=c++11 -pedantic -Wall
DEPS = TicTacToe.h
OBJ = TicTacToe.o Main.o 

Main: $(OBJ)
	g++ -o $@ $^
%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CFLAGS)