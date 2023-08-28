#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int key;
    Node *left;
    Node *right;
};

void print_inorder(Node *node) {
    if (node == NULL)
        return;
    print_inorder(node->left);
    printf("%d  ", node->key);
    print_inorder(node->right);
}

Node *create_node(int key) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int find_height(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int left_height = find_height(node->left);
    int right_height = find_height(node->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

int get_balance_factor(Node *node) {
    return find_height(node->left) - find_height(node->right);
}

Node *right_rotate(Node *y) {
    Node *x = y->left;
    Node *temp = x->right;
    x->right = y;
    y->left = temp;
    return x;
}

Node *left_rotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;
    y->left = x;
    x->right = temp;
    return y;
}

Node *find_min(Node *node) {
    if (node == NULL || node->left == NULL) {
        return node;
    }

    return find_min(node->left);
}

Node *insert(Node *node, int key) {
    if (node == NULL)
        return create_node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    int balance_factor = get_balance_factor(node);

    if (balance_factor > 1 && key < node->key)
        return right_rotate(node);

    if (balance_factor < -1 && key > node->key)
        return left_rotate(node);

    if (balance_factor > 1 && key > node->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance_factor < -1 && key < node->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

int main() {
    Node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 18);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 1);

    print_inorder(root);
    printf("\n");
}