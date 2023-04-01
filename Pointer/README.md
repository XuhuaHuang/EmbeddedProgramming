# Understanding Pointers in C/C++

## Commonly Seen Implementation of `size_t`

```C++
#ifndef __SIZE_T
#define __SIZE_T
typedef unsigned int size_t
#endif
```

## Comonly Seen Pre-defined Data Type

- `size_t`: unsigned integer; safely shows the length of the pointer; return type of `sizeof()` function.  
  Common parameter of functions like `malloc()` and `strlen()`.  
  Use the `%zu` placeholder, `%u` or `%lu`.
- `ptrdiff_t`: mathematic operation on pointers.
- `intptr` and `uintptr_t`: to store the address of a pointer.

## Pointer to an Unsigned Integer with `uintptr_t`

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
- `==`, `!=`, `>`, ... etc. operator: comparison.

### Add an Integer to a Pointer

Adding an integer to a pointer is equivalent to move to a memory address with that exact logical memory address.  
In the example below, self-increment the pointer is equivalent to adding the numeric value of the length of an integer (4-bit) to the logical memory address.

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

The term "double pointers" refer to pointers that point to a pointer variable; it is most comonly seen as `char** argv (argument vector)` as parameters for the main function in C/C++. See below for an example.

```C++
/* Declare a character array to store all the books' name. */
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
bestBooks[2] = &books[5]; // char** bestBooks has been populated with contents.

englishBooks[0] = &books[0];
englishBooks[1] = &books[1];
englishBooks[2] = &books[5];
englishBooks[3] = &books[6]; // char** englishBooks has been populated with contents.

/* Print elements and verify. */
printf("%s\n", *englishBooks[1]); // "Wuthering Heights"
```

### Double-pointer Parameters in Functions

When a pointer is parsed to functions, the value gets parsed, instead of the address. If the original pointer needs to be modified in the function, not the duplicated one, we need to parse a pointer to a pointer.  
The following function uses the first parameter of the function to store allocated memory. In this particular function, memory will be allocated, then initialized.

```C++
void allocateArray(int** arr, const int size, int initValue) {
  /**
   * Modify the content of the original pointer
   * by de-referencing the double pointer, which gives the original int*.
   */
  *arr = (int*)malloc(size * sizeof(int));
  // check whether the allocation was successful
  if (*arr != NULL) {
    // iterate through the array and assign initial value
    for(int i = 0; i < size; ++i) {
      *(*arr+i) = initValue;
    }
  }
}

int main(void) {
  int* vector = NULL;
  allocateArray(&vector, 5, 45);
  /* &vector gives the function the address of the pointer. */
}
```

---

## Dynamic Memory Allocation

In C, there are 3 basic steps for dynamic memory allocation:

- Use `malloc()` function to allocate memory.
- Use allocated block(s) of memory to support the usage of the application.
- Use `free()` function to release the memory. For example:

```C++
int* pi = (int*)malloc(sizeof(int)); /* Using explicit convertion syntax (int*) for the rvalue. */
/* When allocating specific number of bytes for built-in data type,
 * try using the sizeof() function.
 */
*pi = 5; /* De-reference the pointer and assign a value to it. */
printf("Address: %p, Content: %d", &pi, *pi);
free(pi);
```

### Static and Global Pointers and `malloc()`

Functions are not allowed when initializing static or global variables.

```C++
// global namespace
// the following line gives an compile-time error.
// static int* pi = malloc(sizeof(int));
// use this instead:
static int* pi;
pi = malloc(sizeof(int));
// from the compiler's view, `=` operator in the initialization phase is different
// than the one used for assignment
```

### Function `calloc()`

This function will clear the memory while allocating. All slots will be set to hold the value of a binary 0 (false).  
`void* calloc(size_t numElements, size_t elementSize);`

- The total amount of memory allocated will have the size of (numElments \* elementSize), as the parameters suggest.
- It returns the pointer pointing to the first element of allocated memory. This function was originally used to help allocate memory for arrays.
- Returns `NULL` if allocation failed; `errno` will be set to `ENOMEM` on `POSIX`.
- Use `malloc` and `memset` for the same effect:

  ```C++
  int* pi = (int*)malloc(sizeof(int));
  memset(pi, 0, 5*sizeof(int));
  ```

- Note that `calloc` may take longer to execute than `malloc` does.

### Function `realloc()`

Function to reallocate memory to offer support like variadic-length array.  
`void* realloc(void* ptr, size_t size);`

- Note the `size` argument should be different than the size of original `ptr`.
- Returns the pointer pointing to the re-allocated memory.
- If the pointer is not `NULL`, and the `size` argument is 0, the pointer will be freed.
- Returns `NULL` if allocation failed and `ptr` stays unchanged; `errno` will be set to `ENOMEM` on `POSIX`.

```C++
char* hexa;
char* hexaCopy;
hexa = (char*)malloc(16);
strcpy(hexa, "0123456789AB");
hexaCopy = (char*)realloc(hexa, 64); /* Allocating more memory. */
// Use explicit conversion to avoid possible compiler complaints.
printf("hexa value: %p [%s]\n.", hexa, hexa);
printf("hexaCopy value: %p [%s]\n.", hexaCopy, hexaCopy);
```

### RAII - Resource Acquisition is Initialization

A technology invented by Bjarne Stroustrup, to allocate and release memory in C++ program, regardless the program throws an exception or not.  
`GNU Core` uses the `RAII_VARIABLE` macro to implement this feature. See below for the function-like macro definition.

```C++
#define RAII_VARIABLE(vartype, varname, initval, dtor) \
  void _dtor_ ## varname (vartype * v) { dtor(*v) };   \
  vartype varname __attribute__((cleanup(_dtor ## varname))) = (initval)
```

See below for a small demonstration; the following code declare a variable of type `char*`, and allocated 4 bytes of memory. When the variable `name` goes out of scope, the `free()` function will be called as the destructor.

```C++
void raiiExample(void) {
  RAII_VARIABLE(char*, name, (char*)malloc(32), free);
  strcpy(name, "RAII example demonstration");
  printf("%s\n", name); /* RAII example demonstration */
}
```

### Safer `free()` Function Implementation

See directory `..\Util\safe_free.hpp` for definition and demonstration.  
For short, set the pointer to `NULL` after invoking the `free()` function on such pointer.

---

## Function Pointer

See directory `.\FnPointer\FnPointer.cpp` and `function_pointers.cpp`.

```C++
int add(const int x, const int y) {
  return x + y;
}

int multiply(const int x, const int y) {
  return x * y;
}

int (*pfn_arithmetic)(int, int);
pfn_arithmetic = add;
// use add function through function pointer
std::cout << "pfn_arithmetic(3, 7) = " << pfn_arithmetic(3, 7) << "\n"; // 10
pfn_arithmetic = multiply; // point to the multiply function
std::cout << "pfn_arithmetic(3, 7) = " << pfn_arithmetic(3, 7) << "\n"; // 21
```
