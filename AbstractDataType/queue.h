/**
 * @brief Contains declaration of a commonly-seen data structure queue implemented in C.
 * 
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

/**
 * @brief The compiler will treat "queue"
 * as in incomplete type.
 * queue is an opaque data type.
 */
typedef struct _queue queue;

// the following function prototypes all ask for a queue*
// the compiler knows what to do with a pointer (an address)
// so long as it is NOT de-referenced
queue* q_create(int max_size);
void q_destroy(queue *q);
bool q_empty(queue *q);
bool q_full(queue *q);
bool q_endqueue(queue *q, int value);
int q_dequeue(queue *q);

#endif
