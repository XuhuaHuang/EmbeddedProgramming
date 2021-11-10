.linkedlist: all clean
all: linkedlist
linkedlist: linked_list.o
	gcc -o linkedlist linked_list.o
linked_list.o: linked_list.c
	gcc -c linked_list.c
clean:
	rm -f main.o linkedlist