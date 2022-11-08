.AbstractDataTypes_in_C: all clean
all: AbstractDataTypes_in_C
AbstractDataTypes_in_C: queue.o main.o
	gcc queue.o main.o -o AbstractDataTypes_in_C
queue.o: queue.h queue.c
	gcc -c queue.c -o queue.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	rm -f ./*.o
	rm AbstractDataTypes_in_C