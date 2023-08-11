#ifndef LIST_H
#define LIST_H

// A linked list node
typedef struct Node Node;
struct Node {
    int data;
    Node *next;
    Node *prev;
};

void list_insert(Node **head_ref, int data, int index);
void list_delete(Node **head_ref, int index);
void list_display(Node *head);
int list_length(Node *head);

#endif //LIST_H
