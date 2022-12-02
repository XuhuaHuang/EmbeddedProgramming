
CC=g++
CFLAGS=-g -Wall
OPTFLAG=-O2

all:dealer.o main.o
	$(CC) $(CFLAGS) $(OPTFLAG) dealer.o main.o -o exec

dealer.o:dealer.cpp dealer.h
	$(CC) $(CFLAGS) $(OPTFLAG) -c dealer.cpp -o dealer.o

main.o:main.cpp
	$(CC) $(CFLAGS) $(OPTFLAG) -c main.cpp -o main.o

clean:
	rm -rf *.o
	rm exec
