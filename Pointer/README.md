# Understanding Pointers in C/C++

## Commonly Seen Implementation of `size_t`
```C++
#ifndef __SIZE_T
#define __SIZE_T
typedef unsigned int size_t
#endif
```

## Comonly Seen Pre-defined Data Type
* `size_t`: unsigned integer; safely shows the length of the pointer; return type of `sizeof()` function.  
  Common parameter of functions like `malloc()` and `strlen()`.  
  Use the `%zu` placeholder, `%u` or `%lu`.
* `ptrdiff_t`: mathematic operation on pointers.
* `intptr` and `uintptr_t`: to store the address of a pointer.

## Pointer to an Unsigned Integer: `uintptr_t`
```C++
int num;
// uintptr_t *pu = &num;
/* gives a compiler error. Require explicit conversion. */
uintptr_t *pu = (uintptr_t*)&num;
```
Note: try to avoid converting pointer to integer; if the pointer is 64-bit, and an integer is only 32-bit, info will be lost. Pay more attention to portability and safety.

---

## Operators with Pointers
- `*` operator: to declare, dereference a pointer.
- `->` operator: to access to segment the pointer refers to.
- `+` and `-` operator: plus and minus.
- `==`, `!=`, `>`, ... etc. operator: comparsion.

### Add an Integer to a Pointer
Adding an integer to a pointer is equivalent to move to a memory address with that exact logical memory address.  
In the example below, self-increment the pointer is equivalent to adding the numeric vaue of the length of an integer (4-bit) to the logical memory address.
```C++
int vector[] = { 28, 41, 7 };
int *pi = vector;
/* vector returns the address of the array, i.e. vector[0] */
printf("%p\n", pi);   /* logical address: 0x7ffdbcc0ee1c */
printf("%d\n", *pi);  /* 28 */

pi += 1;
printf("%p\n", pi);   /* logical address: 0x7ffdbcc0ee20 */
printf("%d\n", *pi);  /* 41 */

pi += 1;
printf("%p\n", pi);   /* logical address: 0x7ffdbcc0ee24 */
printf("%d\n", *pi);  /* 7 */
```

---

## Double Pointers
The term "double pointers" refer to pointers that point to a pointer variable; it is most comonly seen as `char** argv (argument vector)` in C/C++. See below for an example.
```C++
/* Declare a charater array to store all the books' name. */
char* books[] = {
  "A Tale of Two Cities",
  "Wuthering Heights", "Famous Last Words",
  "Odyssey", "Don Quixote", "Moby-Dick",
  "Hamlet", "Gulliver's Travels"
};

/* Declare other 2 arrays to store the address of elements in char* bookTitles[]. */
char** bestBooks[3];
char** englishBooks[4];

/* Access the elements with [] operator, then refer to the address of them. */
bestBooks[0] = &books[0];
bestBooks[1] = &books[3];
bestbooks[2] = &books[5]; // char** bestBooks has been populated with contents.

englishBooks[0] = &books[0];
englishBooks[1] = &books[1];
englishBooks[2] = &books[5];
englishBooks[3] = &books[6]; // char** englishBooks has been populated with contents.

/* Print elements and verify. */
printf("%s\n", *englishBooks[1]); // "Wuthering Heights"
```

---

## Dunamic Memory Allocation
In C, there are 3 basic steps for dynamic memory allocation:
- Use `malloc()` function to allocate memory.
- Use allocated block(s) of memory to support the usage of the application.
- Use `free()` function to release the memory. For example:
```C++
int* pi = (int*)malloc(sizeof(int)); /* Using explicit convertion syntax (int*) for the rvalue. */
*pi = 5; /* De-reference the pointer and assign a value to it. */
printf("Address: %p, Content: %d", &pi, *pi);
free(pi);
```