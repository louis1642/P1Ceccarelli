STD = c++11
FLAGS = -pedantic -Wall
DEPS = main.cpp Account.h
main: main.o
	g++ -o main main.o
main.o: ${DEPS}
	g++ -c main.cpp -std=${STD} ${FLAGS}