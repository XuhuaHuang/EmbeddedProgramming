/**
 * @file queue.c
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2022-11-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "queue.h"

typedef struct _queue {
    int *values;
    int head, tail;
    int num_entries, size;
} queue;

queue *q_create(int max_size) {
    queue *q = malloc(sizeof(queue));
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);
    q->num_entries = 0; // the queue is empty for now
    q->head = 0;
    q->tail = 0;
    return q;
}

void q_destroy(queue *q) {
    free(q->values);
    free(q);
    q = NULL;
}

bool q_empty(queue *q) {
    return (q->num_entries == 0);
}

bool q_full(queue *q) {
    return (q->num_entries == q->size);
}

bool q_endqueue(queue *q, int value) {
    // no more entry space available
    if (q_full(q)) {
        return false;
    }
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;

    return true;
}

int q_dequeue(queue *q) {
    int result;

    if (q_empty(q)) {
        return QUEUE_EMPTY;
    }

    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries--;

    return result;
}
