all:student.o studentclub.o numbers.o main.o
	g++ student.o studentclub.o numbers.o main.o -o pointer_lab.exe
student.o:Student.hpp
	g++ -c Student.hpp -o student.o
studentclub.o:StudentClub.hpp
	g++ -c StudentClub.hpp -o studentclub.o
numbers.o:Numbers.hpp
	g++ -c Numbers.hpp -o numbers.o
main.o:main.cpp
	g++ -c main.cpp -o main.o
