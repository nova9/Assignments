#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *prev;
    Node *next;
};

void display_list(Node *last) {
    if (last == NULL) {
        printf("List empty\n");
        return;
    }

    bool first_passed = false;
    for (Node *i = last->next; 1; i = i->next) {
        if (first_passed && i == last->next) {
            break;
        }
        if (!first_passed) {
            first_passed = true;
        }
        printf("%d <-> ", i->data);
    }
    printf("%d", last->next->data);
    printf(" (circular)\n");
}

Node *addToEmpty(Node *last, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node;
    new_node->prev = new_node;

    return new_node;
}

Node *insertAtBegin(Node *last, int data) {
    if (last == NULL) {
        return addToEmpty(last, data);
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = last->next;
    new_node->next->prev = new_node;
    new_node->prev = last;
    last->next = new_node;

    return last;
}

Node* insertAtEnd(Node* last, int data) {
    if (last == NULL) {
        return addToEmpty(last, data);
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = last->next;
    new_node->next->prev = new_node;
    new_node->prev = last;
    last->next = new_node;

    return new_node;
}

Node *deleteAtBegin(Node *last) {
    if (last == last->next) {
        return NULL;
    }
    Node *first = last->next;
    last->next = first->next;
    last->next->prev = last;
    free(first);
    return last;
}

Node *deleteAtEnd(Node *last) {
    if (last == last->next) {
        return NULL;
    }

    Node *prev = last->prev;
    printf("prev = %d\n", prev->data);
    prev->next = last->next;
    prev->next->prev = prev;
    free(last);
    return prev;
}

int main() {
    struct Node *last = NULL;

    last = insertAtEnd(last, 10);
    last = insertAtEnd(last, 20);
    last = insertAtEnd(last, 30);

    printf("After insertion: ");
    display_list(last);


    last = deleteAtBegin(last);
    last = deleteAtEnd(last);

    printf("After deletion: ");
    display_list(last);
}