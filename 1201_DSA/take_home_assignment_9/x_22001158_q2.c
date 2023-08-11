#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListNode ListNode;
struct ListNode {
    int data;
    ListNode *next;
};

void push(ListNode **top, int data) {
    ListNode* new_node = malloc(sizeof(ListNode));
    if (*top == NULL) {
        new_node->data = data;
        new_node->next = NULL;
        *top = new_node;
        return;
    }
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

int pop(ListNode **top) {
    ListNode *temp = *top;
    if (*top == NULL) {
        printf("Error: Trying to pop from empty stack\n");
        exit(1);
    } else {
        int temp_data = temp->data;
        *top = (*top)->next;
        free(temp);
        return temp_data;
    }
}

void display_list(ListNode *top) {
    ListNode* current = top;
    if (top == NULL) {
        printf("\nStack is Empty");
    } else {
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
    }
    printf("\n");
}

typedef struct Node Node;
struct Node {
    int value;
    Node *left;
    Node *right;
};

void printInorder(Node *node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

void printPreorder(Node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->value);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node *node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->value);
}

Node *newNode(int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

void processInorder(Node *root, Node *node, ListNode **top) {
    if (node == NULL)
        return;
    processInorder(root, node->left, top);
    if(node != root) {
        if (*top == NULL || node->value != (*top)->data) {
            push(top, node->value);
        } else {
            pop(top);
        }
    }
    processInorder(root, node->right, top);
}

bool isSymmetric(Node *root) {
    ListNode *top = NULL;
    processInorder(root, root, &top);
    if(top == NULL) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(2);

    root->right->left = newNode(4);
    root->right->right = newNode(5);

    root->left->right = newNode(4);
    root->left->left = newNode(5);

    isSymmetric(root) ? printf("Symmetric\n") : printf("Asymmetric\n");
}