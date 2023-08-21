#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Queue Queue;
struct Queue {
    int front;
    int rear;
    int max_queue;
    int count;
    char *elements[];
};

Queue *init_queue(int max_queue) {
    Queue *queue = malloc(sizeof(int) *  4 + sizeof(char *) * max_queue);
    queue->front = queue->rear = -1;
    queue->max_queue = max_queue;
    queue->count = 0;
    return queue;
}

bool is_full(Queue *queue) {
    return queue->count == queue->max_queue;
}

bool is_empty(Queue *queue) {
    return queue->count == 0;
}

void enqueue(Queue *queue, char *value) {
    if (is_full(queue)) {
        printf("Queue Overflow\n");
        exit(1);
    }

    if (is_empty(queue))
        queue->front++;

    queue->count++;
    queue->rear = (queue->rear + 1) % queue->max_queue;
    queue->elements[queue->rear] = value;
}

char *dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue Underflow\n");
        exit(1);
    }

    char *dequeued_value = queue->elements[queue->front];

    queue->front = (queue->front + 1) % queue->max_queue;
    queue->count--;

    return dequeued_value;
}

void display_queue(Queue *queue) {
    for (int i = queue->front; 1; i = (i + 1) % queue->max_queue) {
        printf("%s ", queue->elements[i]);
        if (i == queue->rear) {
            break;
        }
    }
}

struct Stack {
    int max_size;
    int top;
    int data[];
};
typedef struct Stack Stack;


bool stack_is_full(Stack *stack) {
    return stack->top == stack->max_size - 1;
}
bool stack_is_empty(Stack *stack) {
    return stack->top == -1;
}
int peek(Stack *stack) {
    return stack->data[stack->top];
}
void push(Stack *stack, int value) {
    if(stack_is_full(stack)) {
        printf("Stack Overflow\n");
        exit(1);
    }

    stack->data[++stack->top] = value;
}
int pop(Stack *stack) {
    if(stack_is_empty(stack)) {
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

void display_stack(Stack *stack) {
    for(int i = stack->top; i >= 0 ; i--) {
        printf("|%d|\n", stack->data[i]);
    }
    printf("\n");
}

char *to_binary(int decimal) {
    Stack *s = init_stack(100);
    int result = decimal;
    while(1) {
        if (result == 1) {
            push(s, 1);
            break;
        }
        int remainder = result % 2;
        result = result / 2;
        push(s, remainder);
    }

    char *binary_string = malloc(sizeof(char));
    binary_string[0] = '\0';
    int binary_string_length = 0;

    while(!stack_is_empty(s)) {
        char digit_string[2] = {pop(s) + '0', '\0'};
        binary_string = realloc(binary_string, sizeof(char) * (binary_string_length + 2));
        binary_string_length++;
        strcat(binary_string, digit_string);
    }

    free(s);

    return binary_string;
}

int main() {
    printf("Enter the value for N: ");
    int N;
    scanf("%d", &N);
    printf("Binary numbers between 0 to %d are: ", N);

    Queue *q = init_queue(N);

    for (int i = 1; i <= N; i++) {
        enqueue(q, to_binary(i));
    }

    display_queue(q);
    printf("\n");
}