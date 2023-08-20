#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
    Node *prev;
};

void insert_at_end(Node **start, int val) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory overflow\n");
        exit(1);
    }
    new_node->data = val;

    if (*start == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *start = new_node;
    }

    (*start)->prev->next = new_node;
    new_node->prev = (*start)->prev;
    new_node->next = *start;
    (*start)->prev = new_node;
}

void display(Node *start) {
    Node *ptr = start;

    if (start == NULL) {
        printf("List empty\n");
        return;
    }

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}

Node *search(Node *start, int val) {
    if (start == NULL) {
        printf("List underflow\n");
        exit(1);
    }

    Node *ptr = start;
    while (ptr != start->prev) {
        if (ptr->data == val) {
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}

int main () {
    Node *start = NULL;

    insert_at_end(&start, 4);
    insert_at_end(&start, 8);

    Node *searched = search(start, 2);
    searched != NULL ? printf("search = %d\n", search(start, 2)->data) : printf("Not found\n");

    display(start);
}