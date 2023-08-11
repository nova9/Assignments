#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

Stack create_stack() {
    Stack stack = {-1, NULL};
    return stack;
}

void stack_push(Stack *stack, int data) {
    list_insert(&stack->elements, data, list_length(stack->elements));
}

void stack_pop(Stack *stack) {
    int length = list_length(stack->elements);
    if (length == 0) {
        printf("Stack Underflow\n");
        return;
    }
    list_delete(&stack->elements, length - 1);
}

void stack_display(Stack *stack) {
    list_display(stack->elements);
}