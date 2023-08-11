#include <stdio.h>
#include <stdlib.h>

#include "includes/stack.h"

int main() {
    Node *head = NULL;
    list_insert(&head, 3, 0);
    list_insert(&head, 5, 1);
    list_insert(&head, 8, 2);
    list_insert(&head, 10, 3);

    Node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    Node *current = last;
    printf("current = %d\n", current->data);
    while (current->data > 9) {
        current = current->prev;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = 9;
    new_node->next = current->next;
    current->next->prev = new_node;
    current->next = new_node;
    new_node->prev = current;


    list_display(head);
}