#include <stddef.h>


typedef struct stack {
	size_t count;
	size_t capacity;
	void** data;
} stack_t;

stack_t* new_stack(size_t capacity);
