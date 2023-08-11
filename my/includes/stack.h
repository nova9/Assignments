#include "list.h"

#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;
struct Stack {
    int top;
    Node *elements;
};

Stack create_stack();
void stack_push(Stack *stack, int data);
void stack_display(Stack *stack);
void stack_pop(Stack *stack);

#endif //STACK_H
