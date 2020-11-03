all:inheritance.o Inheritance_lab_main.o
	g++ inheritance.o Inheritance_lab_main.o -o exec
inheritance.o:Inheritance_lab_functions.cpp Inheritance_lab_header.h
	g++ -c Inheritance_lab_functions.cpp
inheritancemain.o:Inheritance_lab_main.cpp Inheritance_lab_header.h
	g++ -c Inheritance_lab_main.cpp
clean:
	rm -rf *.o
	rm exec
