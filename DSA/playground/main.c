#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack Stack;
struct Stack {
    int top;
    int elements[MAX];
};

int is_full(Stack *stack) {
    return stack->top == MAX - 1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        exit(0);
    }

    stack->elements[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }

    return stack->elements[stack->top--];
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->elements[stack->top];
}

void display(Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d  ", stack->elements[i]);
    }
    printf("\n");
}

Stack *postfix_evaluate(char *expression) {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;

    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        if ('0' <= c && c <= '9') {
            push(stack, c - '0');
        } else {
            int value2 = pop(stack);
            int value1 = pop(stack);

            switch (c) {
                case '+':
                    push(stack, value1 + value2);
                    break;
                case '-':
                    push(stack, value1 - value2);
                    break;
                case '*':
                    push(stack, value1 * value2);
                    break;
                case '/':
                    push(stack, value1 / value2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }

    return stack;
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int is_operand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ('0' <= ch && ch <= '9');
}

char *if2pf(char *exp) {
    int i, k;

    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;

    for (i = 0, k = -1; exp[i]; ++i) {
        if (is_operand(exp[i]))
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')') {
            while (!is_empty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!is_empty(stack) && peek(stack) != '(') {
                printf("Invalid Expression");
                exit(1);
            } else
                pop(stack);
        } else // an operator is encountered
        {
            while (!is_empty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }

    }

    while (!is_empty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s", exp);
    return exp;
}


int main() {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;
    for (int i = 1; i <= 12; i++) {
        if (i % 4 != 0) {
            push(stack, i);
        } else {
            if (i % 2 == 0) {
                pop(stack);
            }
        }
    }

    display(stack);
}