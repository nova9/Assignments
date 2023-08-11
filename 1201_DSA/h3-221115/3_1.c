#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int max_size;
    int top;
    int data[];
};
typedef struct Stack Stack;


bool is_full(Stack *stack) {
    return stack->top == stack->max_size - 1;
}
bool is_empty(Stack *stack) {
    return stack->top == -1;
}
int peek(Stack *stack) {
    return stack->data[stack->top];
}
void push(Stack *stack, int value) {
    if(is_full(stack)) {
        printf("Stack Overflow\n");
        exit(1);
    }

    stack->data[++stack->top] = value;
}
int pop(Stack *stack) {
    if(is_empty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

Stack *init_stack(int max_size) {
    Stack *stack = malloc(sizeof(int) * (max_size + 1 + 1));
    stack->max_size = max_size;
    stack->top = -1;
    return stack;
}

void display(Stack *stack) {
    for(int i = stack->top; i >= 0 ; i--) {
        printf("|%d|\n", stack->data[i]);
    }
    printf("\n");
}

char *get_string(){
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while(EOF != (ch=getchar()) && ch != '\n'){
        str[len++] = ch;
        if(len == size){
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

int main() {
    printf("Enter a string: ");
    char *string = get_string();

    int string_length = strlen(string);

    Stack *string_stack = init_stack(string_length);
    for(int i = 0; i < string_length; i ++) {
        push(string_stack, string[i]);
    }

    for(int i = 0; i < string_length; i ++) {
        printf("%c", pop(string_stack));
    }
    printf("\n");

}

