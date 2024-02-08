#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct stack my_stack;

my_stack *my_stack_init();

bool my_stack_empty(my_stack *stack);

size_t my_stack_size(my_stack *stack);

void *my_stack_top(my_stack *stack);

void *my_stack_push(my_stack *stack, void *val);

void *my_stack_pop(my_stack *stack);

void my_stack_free(my_stack *stack);

#endif // MY_STACK_H
