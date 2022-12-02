all:dealer.o dealermain.o
	g++ dealer.o dealermain.o -o exec
dealer.o:dealer.cpp dealer.h
	g++ -c dealer.cpp
dealermain.o:dealermain.cpp dealer.h
	g++ -c dealermain.cpp
clean:
	rm -rf *.o
	rm exec
