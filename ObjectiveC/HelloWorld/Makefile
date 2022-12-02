
CC=g++
CFLAGS=-g -Wall
OPTFLAG=-O2

all:main.o
	$(CC) $(CFLAGS) $(OPTFLAG) main.o -o helloworld
main.o:helloworld.m
	$(CC) $(CFLAGS) $(OPTFLAG) -I "C:\GNUstep\GNUstep\System\Library\Headers" -L "C:\GNUstep\GNUstep\System\Library\Libraries" -o main.o helloworld.m -lobjc -lgnustep-base -fconstant-string-class=NSConstantString
