# Interface

> Make interfaces easy to use correctly and hard to use incorrectly.

## Avoid `non-const` Global Variables

- Testability: can not test entities in isolation.
- Refactoring: challenging to refactor code.
- Optimization: can not easily rearrange function invocations or spread invocations to threads.
- Concurrency: non-const global variables are shared and mutable, prone to data-race.

## Avoid Singletons

- A singleton is just a global variable

## Make Good Interfaces
- Make interfaces explicit
- Make interfaces precise and strongly typed
- Keep the number of function arguments low
- Avoid adjacent unrelated parameters of the same type
