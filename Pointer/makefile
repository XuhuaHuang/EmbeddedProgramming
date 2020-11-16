all:Pointer_lab_fn.o Pointer_lab_main.o
	g++ Pointer_lab_fn.o Pointer_lab_main.o -o exec
Pointer_lab_fn.o:Pointer_lab_fn.cpp Pointer_lab.h
	g++ -c Pointer_lab_fn.cpp
Pointer_lab_main.o:Pointer_lab_main.cpp Pointer_lab.h
	g++ -c Pointer_lab_main.cpp
