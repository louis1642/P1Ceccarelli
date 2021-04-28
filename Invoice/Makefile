STD = c++11
FLAGS = -pedantic -Wall

main: main.o invoice.o
	g++ -o main main.o invoice.o
main.o: main.cpp Invoice.h
	g++ -c main.cpp -std=${STD} ${FLAGS}
invoice.o: Invoice.cpp Invoice.h
	g++ -c invoice.cpp -std=${STD} ${FLAGS}