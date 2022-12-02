CC=gcc
CFLAGS=-g -Wall
OPTFLAG=-O2

.progbar: all clean
all: progbar
progbar: main.o
	$(CC) $(CFLAGS) $(OPTFLAG) -o progbar main.o

main.o: main.c
	$(CC) $(CFLAGS) $(OPTFLAG) -c main.c -o main.o

clean:
	rm -f main.o progbar
