#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static size_t allocation_attempts;
static size_t failing_allocation;
static size_t live_allocations;

static void* test_malloc(size_t size) {
  ++allocation_attempts;
  if (allocation_attempts == failing_allocation) {
    return NULL;
  }

  void* allocation = malloc(size);
  if (allocation != NULL) {
    ++live_allocations;
  }
  return allocation;
}

static void test_free(void* allocation) {
  if (allocation != NULL) {
    --live_allocations;
  }
  free(allocation);
}

// Compile the implementation with test-only allocation hooks. The public header
// is included first so the macros do not rewrite standard library declarations.
#define malloc test_malloc
#define free test_free
#include "../queue.c"
#undef malloc
#undef free

static void check(bool condition, const char* expression, int line) {
  if (!condition) {
    fprintf(stderr, "Check failed at line %d: %s\n", line, expression);
    exit(EXIT_FAILURE);
  }
}

#define CHECK(condition) check((condition), #condition, __LINE__)

int main(void) {
  CHECK(q_create(0) == NULL);
  CHECK(q_create(-1) == NULL);
  CHECK(q_create(INT_MIN) == NULL);
  CHECK(allocation_attempts == 0);
  CHECK(live_allocations == 0);

  failing_allocation = 1;
  CHECK(q_create(3) == NULL);
  CHECK(allocation_attempts == 1);
  CHECK(live_allocations == 0);

  allocation_attempts = 0;
  failing_allocation  = 2;
  CHECK(q_create(3) == NULL);
  CHECK(allocation_attempts == 2);
  CHECK(live_allocations == 0);

  allocation_attempts = 0;
  failing_allocation  = 0;
  queue* q            = q_create(3);
  CHECK(q != NULL);
  CHECK(allocation_attempts == 2);
  CHECK(live_allocations == 2);
  CHECK(q_empty(q));
  CHECK(!q_full(q));
  CHECK(q_endqueue(q, 10));
  CHECK(q_endqueue(q, 20));
  CHECK(q_endqueue(q, 30));
  CHECK(q_full(q));
  CHECK(!q_endqueue(q, 40));
  CHECK(q_dequeue(q) == 10);
  CHECK(q_endqueue(q, 40));
  CHECK(q_dequeue(q) == 20);
  CHECK(q_dequeue(q) == 30);
  CHECK(q_dequeue(q) == 40);
  CHECK(q_empty(q));
  CHECK(q_dequeue(q) == QUEUE_EMPTY);
  CHECK(q_endqueue(q, 50));
  CHECK(q_dequeue(q) == 50);
  q_destroy(q);
  CHECK(live_allocations == 0);

  puts("Queue creation, allocation cleanup, and FIFO checks passed.");
  return EXIT_SUCCESS;
}
