all:mytime.o mytimeMain.o
	g++ mytime.o mytimeMain.o -o exec
mytime.o:mytime.cpp mytime.h
	g++ -c mytime.cpp
mytimeMain.o:mytimeMain.cpp mytime.h
	g++ c mytimeMain.cpp
