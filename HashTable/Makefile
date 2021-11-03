.hashtable: all clean
all: hashtable
hashtable: main.o
	gcc -o hashtable main.o
main.o: main.c
	gcc -c main.c
clean:
	rm -f main.o hashtable