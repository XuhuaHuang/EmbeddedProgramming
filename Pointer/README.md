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