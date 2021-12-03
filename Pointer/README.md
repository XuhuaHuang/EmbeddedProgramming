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
