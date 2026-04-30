# Queue Data Structure in C

## Overview

This header file defines a commonly-used data structure: a queue. The queue is implemented in C and provides essential operations to manage a queue. The queue is defined as an opaque data type, meaning its internal structure is not exposed.

## Header File: `queue.h`

### Includes

```cxx
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
```

### Definitions

```cxx
#define QUEUE_EMPTY INT_MIN
```

### Typedefs

```cxx
typedef struct \_queue queue;
```

### Function Prototypes

#### `queue* q_create(int max_size)`

- **Description**: Creates a queue with a specified maximum size.
- **Parameters**:
  - `int max_size`: The maximum size of the queue.
- **Returns**: A pointer to the created queue.

#### `void q_destroy(queue *q)`

- **Description**: Destroys the specified queue and frees all allocated memory.
- **Parameters**:
  - `queue *q`: A pointer to the queue to be destroyed.

#### `bool q_empty(queue *q)`

- **Description**: Checks if the specified queue is empty.
- **Parameters**:
  - `queue *q`: A pointer to the queue to check.
- **Returns**: `true` if the queue is empty, `false` otherwise.

#### `bool q_full(queue *q)`

- **Description**: Checks if the specified queue is full.
- **Parameters**:
  - `queue *q`: A pointer to the queue to check.
- **Returns**: `true` if the queue is full, `false` otherwise.

#### `bool q_endqueue(queue *q, int value)`

- **Description**: Adds a value to the end of the queue.
- **Parameters**:
  - `queue *q`: A pointer to the queue.
  - `int value`: The value to be added to the queue.
- **Returns**: `true` if the value is successfully added, `false` otherwise (e.g., if the queue is full).

#### `int q_dequeue(queue *q)`

- **Description**: Removes and returns the value at the front of the queue.
- **Parameters**:
  - `queue *q`: A pointer to the queue.
- **Returns**: The value at the front of the queue. If the queue is empty, returns `QUEUE_EMPTY`.

## Example Usage

```cxx
#include "queue.h"

int main() {
    queue *q = q_create(10);
    if (q == NULL) {
        printf("Failed to create queue\n");
        return 1;
    }

    q_endqueue(q, 1);
    q_endqueue(q, 2);
    q_endqueue(q, 3);

    while (!q_empty(q)) {
        printf("%d\n", q_dequeue(q));
    }

    q_destroy(q);
    return 0;
}
```

## Notes

- This implementation uses an opaque data type for the queue to hide its internal structure and encourage encapsulation.
- Ensure to handle the memory management properly by destroying the queue when it is no longer needed.
