
CC=g++
CFLAGS=-g -Wall
OPTFLAG=-O2

.circuit: all clean
all: circuit
circuit: circuit.o main.o
	$(CC) $(CFLAGS) $(OPTFLAG) circuit.o main.o -o circuit

circuit.o: circuit.cpp circuit.hpp
	$(CC) $(CFLAGS) $(OPTFLAG) -c circuit.cpp -o circuit.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(OPTFLAG) -c main.cpp -std=c++11 -o main.o

clean:
	rm -f *.o
	rm circuit
