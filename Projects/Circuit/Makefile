.circuit: all clean
all: circuit
circuit: circuit.o main.o
	g++ circuit.o main.o -o circuit
circuit.o: circuit.cpp circuit.hpp
	g++ -c circuit.cpp -o circuit.o
main.o: main.cpp
	g++ -c main.cpp -std=c++11
clean:
	rm -f *.o
	rm circuit