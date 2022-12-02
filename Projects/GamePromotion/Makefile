CC=g++
CFLAGS=-g -Wall
OPTFLAG=-O2

all:gamepromotion.o main.o
	$(CC) $(CFLAGS) $(OPTFLAG) gamepromotion.o main.o -o gamepromotion.exe

gamepromotion.o:GamePromotion.cpp GamePromotion.hpp
	$(CC) $(CFLAGS) $(OPTFLAG) -c GamePromotion.cpp

main.o:main.cpp GamePromotion.hpp
	$(CC) $(CFLAGS) $(OPTFLAG) -c main.cpp -o main.o -std=c++11

clean:
	rm -rf *.o
	rm *.exe
