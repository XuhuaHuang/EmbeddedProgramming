.progbar: all clean
all: progbar
progbar: main.o
	gcc -o progbar main.o
main.o: main.c
	gcc -c main.c
clean:
	rm -f main.o progbar