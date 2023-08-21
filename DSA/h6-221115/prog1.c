#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *next;
};

Node *createList(int n) {
    Node *head = NULL, *current = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        if (i == 0) {
            head = malloc(sizeof(Node));
            current = head;
        } else {
            current->next = malloc(sizeof(Node));
            current = current->next;
        }
        current->data = data;
        current->next = NULL;
    }
    return head;
}

void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node *insert(Node *head, int data, int index) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    if (index == 0) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("The position is beyond the length of the list.\n");
        free(new_node);
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


Node *delete(Node *head, int index) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head;
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
    return head;
}

Node *sortLinkedList(Node *head) {
    int list_length = 0;
    for (Node *i = head; i != NULL; i = i->next)
        list_length++;

    for (int j = 0; j < list_length; j++) {
        Node *prev = NULL;
        for (Node *i = head; i->next != NULL; NULL) {
            Node *a = i;
            Node *b = i->next;
            Node *c = i->next->next;
            if (a->data > b->data) {
                if (prev == NULL) {
                    head = b;
                    b->next = a;
                    a->next = c;
                } else {
                    prev->next = b;
                    b->next = a;
                    a->next = c;
                }
                i = a;
                prev = b;
            } else {
                i = b;
                prev = a;
            }
        }
    }
    return head;
}

Node *deleteLinkedList(Node *head) {
    int list_length = 0;
    for (Node *i = head; i != NULL; i = i->next) {
        list_length++;
    }

    for (int i = list_length - 1; i > 0; i--) {
        head = delete(head, i);
    }

    head->next = NULL;

    free(head);
    return NULL;
}


int main() {
    Node *head = createList(5);

    head = sortLinkedList(head);

    printf("Sorted list: ");
    displayList(head);

    head = deleteLinkedList(head);

    if (head == NULL) {
        printf("Linked list is deleted.\n");
    }
}