#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

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
    printf(RED "FRONT " RESET);
    for (int i = queue->front; 1; i = (i + 1) % queue->max_queue) {
        printf("|" GRN "%s" RESET "| ", queue->elements[i]);
        if (i == queue->rear) {
            break;
        }
    }
    printf(BLU "REAR\n" RESET);
}