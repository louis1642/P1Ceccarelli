CFLAGS = -std=c++11 -Wall -pedantic
DEPS = CNode.h CircleList.h
OBJ = main.o

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o main $^ ${CFLAGS}