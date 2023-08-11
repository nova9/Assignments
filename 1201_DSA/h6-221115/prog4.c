#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
};

void display_list(Node *head) {
    if (head->next == NULL) {
        printf("List empty\n");
        return;
    }

    for (Node *i = head->next; i != NULL; i = i->next) {
        printf("%d -> ", i->data);
    }

    printf("NULL\n");
}

Node *insert(Node *head, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node *last_node = head;
    for (int i = 0; i < head->data; i++) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    head->data++;
    return head;
}

Node *deleteAtIndex(Node *head, int index) {
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head->next;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("The position is beyond the length of the list.\n");
        return head;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    head->data--;
    return head;
}

Node *delete(Node *head, int key) {
    for (
            struct { Node *current; int j; } s = { head->next, 0 };
            s.j < head->data;
            s.j++
            ) {
        if(s.current->data == key) {
            head = deleteAtIndex(head, s.j);
            s.current = head->next;
            s.j = 0;
        } else {
            s.current = s.current->next;
        }
    }
    return head;
}

int main() {
    Node *head = malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);

    printf("After insertion: ");
    display_list(head);

    printf("Delete 30:\n");
    head = delete(head, 30);
    printf("After deletion: ");
    display_list(head);
}