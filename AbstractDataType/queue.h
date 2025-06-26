/**
 * @brief Contains declaration of a commonly-seen data structure queue implemented in C.
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_EMPTY
#define QUEUE_EMPTY INT_MIN
#endif // !QUEUE_EMPTY

/**
 * @brief The compiler will treat "queue"
 * as an incomplete type.
 * queue is an opaque data type.
 */
typedef struct _queue queue;

// the following function prototypes all ask for a queue*
// the compiler knows what to do with a pointer (an address)
// so long as it is NOT de-referenced
queue* q_create(int max_size);
void   q_destroy(queue* q);
bool   q_empty(queue* q);
bool   q_full(queue* q);
bool   q_endqueue(queue* q, int value);
int    q_dequeue(queue* q);

#endif  //!QUEUE_H
