/**
 * @file queue_array.c
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief Source files containing complete demo code.
 * $ cd .\AbstractDataTypes_in_C\src\
 * $ gcc .\queue_array.c
 * $ ./a.exe
 *
 * @version 0.1
 * @date 2022-11-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

typedef struct {
    int* values;
    int head, tail;
    int num_entries, size;
} queue;

queue* q_create(int max_size) {
    queue* q = malloc(sizeof(queue));
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);
    q->num_entries = 0; // the queue is empty for now
    q->head = 0;
    q->tail = 0;
    return q;
}

void q_destroy(queue* q) {
    free(q->values);
    free(q);
    q=NULL;
}

bool q_empty(queue* q) {
    return (q->num_entries == 0);
}

bool q_full(queue* q) {
    return (q->num_entries == q->size);
}

bool q_endqueue(queue* q, int value) {
    // no more entry space available
    if (q_full(q)) {
        return false;
    }
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;

    return true;
}

int q_dequeue(queue* q) {
    int result;

    if (q_empty(q)) {
        return QUEUE_EMPTY;
    }

    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries--;

    return result;
}

int main(void) {
    queue* q = q_create(5);

    q_endqueue(q, 23);
    q_endqueue(q, 34);
    q_endqueue(q, 45);
    q_endqueue(q, 56);
    q_endqueue(q, 78);

    int t;
    while ((t = q_dequeue(q)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }

    q_destroy(q);
    return 0;
}
