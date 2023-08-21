#include <stdbool.h>

struct Queue {
    int front;
    int rear;
    int max_queue;
    int count;
    int elements[];
};
typedef struct Queue Queue;

Queue *init_queue(int max_queue);

bool is_full(Queue *queue);

bool is_empty(Queue *queue);

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

void display_queue(Queue *queue);