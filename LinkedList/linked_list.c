/* mingw32-make */
/* ./linkedlist */
/* cmake .\CMakeLists.txt */

#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a node. */
typedef struct node {
    int value;
    struct node* next;
} node_t;

/* Function prototype. */
void print_node_mem(node_t*); 
void print_linked_list(node_t*);

int main(void) {
    node_t n1, n2, n3;
    node_t* head;

    /* Set some random value for declared nodes. */
    n1.value = 3;
    n2.value = 6;
    n3.value = 9;

    /* Link nodes together. n3 -> n2 -> n1 */
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL; /* Set the end of the linked list is a null pointer. */

    /* Test the print function. */
    print_linked_list(head);

    /* Insert a new node. */
    node_t n4;
    n4.value = 12;
    n4.next = &n3;
    head = &n4;
    printf("After inserting a new node: ");
    print_linked_list(head);

    /* Test function to print the memory address of each node. */
    printf("Blocks of memory used by the linked list: ");
    print_node_mem(head);

    system("pause");
    return 0;
}

void print_node_mem(node_t* _head) {
    node_t* temp = _head;
    /* When the pointer has not reached the end of the linked list. */
    while (temp != NULL) {
        printf("%p -> ", &temp->next);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void print_linked_list(node_t* _head) {
    node_t* temp = _head;
    /* When the pointer has not reached the end of the linked list. */
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    return;
}
