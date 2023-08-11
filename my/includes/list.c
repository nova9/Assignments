#include "list.h"

#include <stdio.h>
#include <stdlib.h>

// Function to insert a new node at a given index
void list_insert(Node **head_ref, int data, int index) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    Node *current = *head_ref;

    // Special case for head node
    if (index == 0) {
        new_node->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = new_node;
        *head_ref = new_node;
    } else {
        // Locate the node before the point of insertion
        for (int i = 0; current != NULL && i < index - 1; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Position is more than the number of nodes.\n");
            return;
        }
        // Insert the new node
        new_node->next = current->next;
        current->next = new_node;
        new_node->prev = current;
        if (new_node->next != NULL)
            new_node->next->prev = new_node;
    }
}

// Function to delete the node at a given index
void list_delete(Node **head_ref, int index) {
    Node *current = *head_ref;

    // Special case for head node
    if (index == 0) {
        *head_ref = current->next;
        if (*head_ref != NULL) (*head_ref)->prev = NULL;
        free(current);
    } else {
        // Locate the node before the point of deletion
        for (int i = 0; current != NULL && i < index; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Position is more than the number of nodes.\n");
            return;
        }
        // Delete the node
        if (current->next != NULL)
            current->next->prev = current->prev;
        if (current->prev != NULL)
            current->prev->next = current->next;
        free(current);
    }
}

// Function to print the doubly linked list
void list_display(Node *head) {
    Node *current = head;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int list_length(Node *head) {
    int length = 0;
    for (Node *i = head; i != NULL; i = i->next) {
        length++;
    }
    return length;
}