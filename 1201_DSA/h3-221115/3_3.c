#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int max_size;
    int top;
    int data[];
};
typedef struct Stack Stack;


bool isFull(Stack *stack) {
    return stack->top == stack->max_size - 1;
}
bool is_empty(Stack *stack) {
    return stack->top == -1;
}
int peek(Stack *stack) {
    return stack->data[stack->top];
}
void push(Stack *stack, int value) {
    if(isFull(stack)) {
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

char *get_string() {
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while(EOF != (ch = getchar()) && ch != '\n'){
        str[len++] = ch;
        if(len == size){
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

char *concat(char *s1, char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    printf("Enter a postfix expression(Operands and operators Seperated by spaces)\n Ex: \"21 34 65 23 + - *\"\n:");
    char *string = get_string();
    string = concat(string, " ");

    int string_length = strlen(string);

    Stack *st = init_stack(string_length);

    char *number_string = "";
    char *remaining;
    for(int i = 0; i < string_length; i++) {
        if(isdigit(string[i])) {
            char char_string[2] = {string[i] , '\0'};
            number_string = concat(number_string, char_string);
        } else if(string[i] == ' ' && strlen(number_string) > 0) {
            long int number = strtol(number_string, &remaining, 0);
            number_string = "";
            push(st, number);
        } else if(string[i] == '*') {
            push(st, pop(st) * pop(st));
        } else if(string[i] == '/') {
            push(st, (1 / pop(st)) * pop(st));
        } else if(string[i] == '+') {
            push(st, pop(st) + pop(st));
        } else if(string[i] == '-') {
            push(st, -pop(st) + pop(st));
        } else if(string[i] != ' ') {
            printf("%c is an invalid characters.\n", string[i]);
            exit(1);
        }
    }

    printf("Answer: %d\n", pop(st));
}

