CC = g++
CFLAGS = -std=c++11 -pedantic -Wall
DEPS = BasePlusCommissionEmployee.h CommissionEmployee.h SalariedEmployee.h Employee.h
OBJ = BasePlusCommissionEmployee.o CommissionEmployee.o SalariedEmployee.o Employee.o testEmployee.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
testEmployee: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)