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
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int stack[MAX_STACK_SIZE];
int top = EMPTY;

bool is_empty() {
    return top == EMPTY;
}

bool is_full() {
    return top == MAX_STACK_SIZE - 1;
}

bool push(int value) {
    if (is_full()) {
        return false;
    }
    stack[++top] = value;
    return true;
}

int pop() {
    if (is_empty()) {
        return STACK_EMPTY;
    }
    int result = stack[top];
    top--;
    return result;
}

int main(int argc, char const *argv[])
{
    int value;

    // Test push
    for (int i = 0; i < 12; i++) {
        if (push(i)) {
            printf("Pushed %d onto stack\n", i);
        } else {
            printf("Stack is full, could not push %d\n", i);
        }
    }

    // Test pop
    for (int i = 0; i < 12; i++) {
        value = pop();
        if (value != STACK_EMPTY) {
            printf("Popped %d from stack\n", value);
        } else {
            printf("Stack is empty, could not pop\n");
        }
    }

    return 0;
}
