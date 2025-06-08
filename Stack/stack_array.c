/**
 * @file stack_array.c
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-06-07
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_STACK_SIZE 10
#define STACK_EMPTY INT_MIN

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} stack_t;

void stack_init(stack_t* s) {
    s->top = -1;
}

bool stack_is_empty(const stack_t* s) {
    return s->top == -1;
}

bool stack_is_full(const stack_t* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

bool stack_push(stack_t* s, int value) {
    if (stack_is_full(s)) {
        return false;
    }
    s->data[++s->top] = value;
    return true;
}

bool stack_pop(stack_t* s, int* out) {
    if (stack_is_empty(s)) {
        return false;
    }
    *out = s->data[s->top--];
    return true;
}

int main(void) {
    stack_t s;
    stack_init(&s);

    for (int i = 0; i < 12; ++i) {
        if (stack_push(&s, i)) {
            printf("Pushed %d\n", i);
        } else {
            printf("Stack full, could not push %d\n", i);
        }
    }

    int value;
    for (int i = 0; i < 12; ++i) {
        if (stack_pop(&s, &value)) {
            printf("Popped %d\n", value);
        } else {
            printf("Stack empty, could not pop\n");
        }
    }

    return 0;
}
