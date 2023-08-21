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
    int elements[];
};

Queue *init_queue(int max_queue) {
    Queue *queue = malloc(sizeof(int) *  4 + sizeof(char *) * max_queue);
    queue->front = queue->rear = -1;
    queue->max_queue = max_queue;
    queue->count = 0;
    return queue;
}

bool queue_is_full(Queue *queue) {
    return queue->count == queue->max_queue;
}

bool queue_is_empty(Queue *queue) {
    return queue->count == 0;
}

void enqueue(Queue *queue, int value) {
    if (queue_is_full(queue)) {
        printf("Queue Overflow\n");
        exit(1);
    }

    if (queue_is_empty(queue))
        queue->front++;

    queue->count++;
    queue->rear = (queue->rear + 1) % queue->max_queue;
    queue->elements[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (queue_is_empty(queue)) {
        printf("Queue Underflow\n");
        exit(1);
    }

    int dequeued_value = queue->elements[queue->front];

    queue->front = (queue->front + 1) % queue->max_queue;
    queue->count--;

    return dequeued_value;
}

void display_queue(Queue *queue) {
    for (int i = queue->front; 1; i = (i + 1) % queue->max_queue) {
        printf("%d ", queue->elements[i]);
        if (i == queue->rear) {
            break;
        }
    }
    printf("\n");
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
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

char *get_string() {
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while (EOF != (ch = getchar()) && ch != '\n') {
        str[len++] = ch;
        if (len == size) {
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

Queue *get_queue(const char *message) {
    printf("%s", message);
    char *elements_string = get_string();

    int *numbers = malloc(sizeof(int));
    int numbers_length = 0;

    char *latest_number_string = malloc(sizeof(char));
    latest_number_string[0] = '\0';
    for (int i = 0; i < strlen(elements_string) + 1; ++i) {
        char character_string[2] = {elements_string[i], '\0'};
        if(elements_string[i] == ' ' || elements_string[i] == '\0') {
            int latest_number = strtol(latest_number_string, NULL, 10);
            latest_number_string = malloc(sizeof(char));
            latest_number_string[0] = '\0';

            numbers = realloc(numbers, sizeof(int) * (numbers_length + 1));
            numbers[numbers_length++] = latest_number;
        } else {
            strcat(latest_number_string, character_string);
        }
    }

    Queue *queue = init_queue(numbers_length);

    for (int i = 0; i < numbers_length; i++) {
        enqueue(queue, numbers[i]);
    }

    return queue;
}

int main() {
    Queue *queue = get_queue("Enter values for the queue(seperated by spaces): ");

    int number_of_values = queue->count;

    printf("Queue before reversing:\n");
    display_queue(queue);

    Stack *stack = init_stack(number_of_values);
    while (!queue_is_empty(queue)) {
        push(stack, dequeue(queue));
    }

    Queue *reversed_queue = init_queue(number_of_values);

    while (!stack_is_empty(stack)) {
        enqueue(reversed_queue, pop(stack));
    }

    printf("Queue after reversing:\n");
    display_queue(reversed_queue);
}