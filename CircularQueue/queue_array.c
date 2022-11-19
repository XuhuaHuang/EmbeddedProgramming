/*****************************************************************//**
 * \file   queue_array.c
 * \brief  FIFO data structure queue implemented in C.
 * 
 * \author Xuhua Huang
 * \date   November 17, 2022
 *********************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct queue {
    int* values;
    int head, tail, num_entries, size;
} queue;

void init_queue(queue* q, int max_size) {
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);
    q->num_entries = 0;
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue* q) {
    return (q->num_entries == 0);
}

bool queue_full(queue* q) {
    return (q->num_entries == q->size);
}

bool queue_destroy(queue* q) {
    free(q->values);
    q->values = NULL;
}

bool enqueue(queue* q, int value) {
    if (queue_full(q)) {
        return false;
    }
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;

    return true;
}

int dequeue(queue* q) {
    int result = 0;
    if (queue_empty(q)) {
        return QUEUE_EMPTY;
    }
    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries--;

    return result;
}

int main(void) {
    queue q1;

    init_queue(&q1, 5);

    enqueue(&q1, 23);
    enqueue(&q1, 34);
    enqueue(&q1, 45);
    enqueue(&q1, 56);
    enqueue(&q1, 78);

    int t = 0;
    while ((t = dequeue(&q1)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }

    queue_destroy(&q1);

    return EXIT_SUCCESS;
}
