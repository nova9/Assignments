#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#include "queue.h"

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

void run(char *priority, int id) {
    printf("Running %s priority process with id %d\n", priority, id);
}

int main() {
    Queue *h_queue = init_queue(9999);
    Queue *l_queue = init_queue(9999);

    int number_of_high_priority_processes;
    int number_of_low_priority_processes;

    printf("How many high priority processes (Less than or equal to 9999): ");
    scanf("%d", &number_of_high_priority_processes);

    printf("How many low priority processes (Less than or equal to 9999): ");
    scanf("%d", &number_of_low_priority_processes);

    for (int i = 0; i < number_of_high_priority_processes; ++i) {
        enqueue(h_queue, i);
    }

    for (int i = 0; i < number_of_low_priority_processes; ++i) {
        enqueue(l_queue, i);
    }

    for (int i = 0; !is_empty(h_queue); ++i) {
        run("High", dequeue(h_queue));
    }

    for (int i = 0; !is_empty(l_queue); ++i) {
        run("Low", dequeue(l_queue));
    }
}