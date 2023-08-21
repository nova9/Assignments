#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    char *value;
    Node *left;
    Node *right;
};

Node *createNode(char *value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

int calculateSubordinates(Node *node, int count) {
    if (node == NULL)
        return count - 1;
    count = calculateSubordinates(node->left, count + 1);
    count = calculateSubordinates(node->right, count + 1);
    return count;
}

int getTotalSubordinates(Node *node) {
    return calculateSubordinates(node, 0);
}

void printInorder(Node *node) {
    if (node == NULL)
        return;

    printInorder(node->left);

    if(getTotalSubordinates(node) > 0) {
        printf("%s - %d subordinate(s)\n", node->value, getTotalSubordinates(node));
    }

    printInorder(node->right);
}

int main() {
    Node *root = createNode("CEO");
    root->left = createNode("Manager 1");
    root->left->left = createNode("Employee 1");
    root->left->right = createNode("Employee 2");
    root->left->right->left = createNode("Employee 3");
    root->right = createNode("Manager 2");
    root->right->left = createNode("Employee 4");

    printInorder(root);
}