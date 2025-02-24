## Basics

Python is interpreted, goes from top to bottom.

### sizeof

the size of int for example is not same between cpus so we need to use `sizeof` operator to get the size of a type.

`%zu` is the formatter to format a sizeof return value in the `printf`

### for loop

1. initialization
2. condition
3. Final-expression

```c
for (i=start, i <= start, i++) //init  cond  final
{
printf("%d", i);
}
```

### While loop
simply for loops, 

### pragma once and header guards

we use include to import other code but we may refefine some variables or functions so in the header file use 

`#pragma once`

## Structs

they look like class in python but simpler, no inheritance or .... .

group variables or fields into one object like structure.
they are only data no method.

`.` to access data.
`->` access pointer

the order matter and the fields are adjacent in mem.

```c
    struct person {
        char* name;
        int age;
        int salary;
    };


    struct person ramin = {
        .age = 22,
        .name = "Ramin",
        .salary = 0,
    };

```

there are paddings in mem when using char, one should order the types in the struct from biggest to smallest to help the compiler minimize the padding
## Pointers

points to a specefic offset from memory

### arrays 
are just pointers!!!!

an array is basically is a pointer to the start of a array.

but pointers are not arrays!!!

when we want sizeof an array c computes the sizeof whole array, not a 64bit (8byte) size (default for pointers), we only get this default size if we specify a pointer to **an element** not the whole array as a pointer.

### strings

`strcpy`
`strcat`
`strlen`
`strcmp`
`strncpy`
`strncat`
`strchr`
`strstr`

### Forward dec

declare a type before actually defining it to tell the compiler I'm going to implement this type soon.

```c
typedef struct Node node_t

typedef struct Node {
	int len;
	node_t next;
}node_t;
```

## Enums
An enumarted list of possible valus,
by def they start at 0 and go on but we can init them to other values.
```c
typedef enum Colors {
	RED = 1,
	GREEN = 50,
	BLUE = 54
} color_t;
```

### Switch case

```c
typedef enum {
	HTTP_NOT_FOUND = 404,
	INTERNAL_SERVER_ERROR = 500	
}HttpError;
```

```c
switch (HttpError code) {
	case HTTP_NOT_FOUND: return "404 not found",
	case INTERNAL_SERVER_ERROR: return "500 internal server error"
}
```

## Unioins
they only can have one type

```c
typedef union sample{
	char* name;
	int num;
} sample_5;
```

Unions store their value in the same memory location, no matter which field or type is actively being used. That means that accessing any field apart from the one you set is generally a **bad idea**

Union size will be the size of largest field in the union.

```c
typedef union IntOrErrMessage {
  int data;
  char err[256];
} int_or_err_message_t;
```

This `IntOrErrMessage` union is designed to hold an `int` 99% of the time. However, when the program encounters an error, instead of storing an integer here, it will store an error message. The trouble is that it’s incredibly inefficient because it allocates 256 bytes for every `int` that it stores!

![[Pasted image 20250212151333.png]]
```c
typedef union Color {
  struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
  } components;
  uint32_t rgba;
} color_t;
```

## The stack and heap
### Stack
When a function is called a stack frame is created in memory to store function parameteres and local vars

_Remember: the stack is only safe to use within the context of the current function!_

In a stack frame always the first ones are func args and after that the local vars are placed, after finishing with func all the allocated mem will be gone.

the memory here is limited and cant grow after compile.
### Heap
Dynamic mem, for example the number of users in a website are not determined at first so we allocate a heap mem and continue to expand it as the user number get larger and larger.

the memory allocated in the heap can grow after compile and can live after the function finished.

`malloc` to allocate heap memory.
If you want to make sure that the memory is properly initialized, you can use the `calloc` function, which allocates the specified number of bytes of memory on the heap and returns a pointer to the allocated memory. This memory is initialized to zero (meaning it contains all zeroes).

```c
// Allocates memory for an array of 4 integers
int *ptr = malloc(4 * sizeof(int));
if (ptr == NULL) {
  // Handle memory allocation failure
  printf("Memory allocation failed\n");
  exit(1);
}
// use the memory here
// ...
free(ptr);
```

we should call free after using the mem.

## Advanced Pointers

### Pointer to Pointer
```c
int main(void) {
    char** ptr_adam = malloc(3 * (sizeof(char*)));
    ptr_adam[0] = malloc(4);
    char* temp = "ram";
    for (int i=0; i<3; i++) {
        ptr_adam[0][i] = temp[i];
    }
    ptr_adam[0][3] = '\0';
    ptr_adam[1] = "mob";
    ptr_adam[2] = "hos";

    ptr_adam[0][0] = 'R'; // this is now safe to do bc we own the mem. (allocated by malloc)


    printf("1. %s, 2. %s, 3. %s, 4. %d", ptr_adam[0], ptr_adam[1], ptr_adam[2], (int)sizeof(char*));

    return 0;
}

```
### void pointer and swaping vars
if we don't know in advance what the type of the var will be we can use `void*` to represent that
```c
void swap_(void* var1, void* var2, size_t size) {

    void* temp = malloc(sizeof(var1));
    memcpy(temp, var2, size);
    memcpy(var2, var1, size);
    memcpy(var1, temp, size);
}

int main(void) {
    
    char* a = "mobin";
    char* b = "ramin";

    swap_(&a, &b, sizeof(int));
    printf("when we swap the vars the a, b are: %s, %s resp\n", a, b);



    return 0;
}
``` 

## Stack data structure

Generics in c is just `void *`

By this we save a pointer the array (which itself is a pointer) in the memory in a struct where capacity and count of the stack is saved.

```c
typedef struct stack {
	int capacity;
	int count;
	void** data;
} stack_t;
```

![[Drawing 2025-02-19 17.41.51.excalidraw]]

#### Stack push
Just check that stack capacity is = to stack count then `realloc` the data with the 2ice memory and put the `obj` at the `stack->count`s place of the data,

```c
void stack_push(stack_t* stack, void* obj) {
    if (stack->capacity == stack->count) {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, sizeof(void*) * stack->capacity);
        if (stack->data == NULL) {return;};
        stack->data[stack->count] = obj;
        stack->count++;

    }
}

```

#### Stack pop
we just set the count to one lower we dont need the worry about the data itself just lower the index

