#include <stdlib.h>
#include "stack.h"


void stack_push(stack_t* stack, void* obj) {
    if (stack->capacity == stack->count) {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, sizeof(void*) * stack->capacity);
        if (stack->data == NULL) {return;};
        stack->data[stack->count] = obj;
        stack->count++;

    }
}


stack_t* new_stack(size_t capacity){
    stack_t* stack = malloc(sizeof(stack_t));
    // always remember to check for null pointer and return sooner
    if (stack == NULL) {return NULL;};
    stack->capacity = capacity;
    stack->count = 0;
    stack->data = malloc(sizeof(void*) * capacity);
    if (stack->data == NULL) {return NULL;};
 
    return stack;
};


