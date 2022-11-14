all:Pointer_lab.o main.o
	g++ Pointer_lab.o main.o -o exec
Pointer_lab.o:Pointer_lab.cpp Pointer_lab.hpp
	g++ -c Pointer_lab.cpp
main.o:main.cpp Pointer_lab.hpp
	g++ -c main.cpp
