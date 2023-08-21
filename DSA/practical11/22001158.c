#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int key;
    Node *left;
    Node *right;
};

void print_inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print_inorder(node->left);
    printf("%d  ", node->key);
    print_inorder(node->right);
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

void print_tree(Node *node, int indent) {
    if (node != NULL) {
        print_tree(node->right, indent + 8);
        for (int i = 0; i < indent; i++)
            printf(" ");
        printf("%d (%d)\n", node->key, get_balance_factor(node));
        print_tree(node->left, indent + 8);
    }
}

Node *create_node(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *right_rotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node *left_rotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

Node *insert(Node *node, int key) {
    if (node == NULL)
        return (create_node(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    int balance_factor = get_balance_factor(node);

    if (balance_factor > 1 && key < node->left->key)
        return right_rotate(node);

    if (balance_factor < -1 && key > node->right->key)
        return left_rotate(node);

    if (balance_factor > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance_factor < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

int main() {
    Node *root = NULL;

    int array[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90};
    int array_length = sizeof(array) / sizeof(int);

    for (int i = 0; i < array_length; i++) {
        root = insert(root, array[i]);
        printf("tree after inserting %d\n", array[i]);
        print_tree(root, 0);
        printf("\n\n");
    }
}