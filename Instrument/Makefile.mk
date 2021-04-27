Instrument: Instrument.o
	g++ -o Instrument Instrument.o
Instrument.o: Instrument.cpp Instrument.h
	g++ -c Instrument.cpp -std=c++11 -pedantic -Wall