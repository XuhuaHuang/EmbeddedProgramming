/**
 * @file main.c
 * @author Xuhua Huang (xuhua.huang.io@gmail.com)
 * @brief To compile and run the demo, execute the following:
 * $ cd .\AbstractDataTypes_in_C\
 * $ mingw32-make all
 *
 * @version 0.1
 * @date 2022-11-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
    queue *q = q_create(5);

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
