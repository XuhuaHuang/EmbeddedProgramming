.angrybirds:all clean
all: angrybirds
angrybirds: angrybirds.o main.o
	g++ angrybirds.o main.o -o angrybirds
angrybirds.o: AngryBirds.h AngryBirds.cpp
	g++ -c AngryBirds.cpp -o angrybirds.o
main.o: main.cpp
	g++ -c main.cpp -o main.o
clean:
	rm -f *.o
	rm angrybirds
