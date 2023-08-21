#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int key;
    Node *left;
    Node *right;
};

Node *new_node(int key) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *node, int key) {
    if (node == NULL) {
        return new_node(key);
    }

    if (key < node->key) {
        node->left = insert_node(node->left, key);
    } else if (key > node->key) {
        node->right = insert_node(node->right, key);
    }
    return node;
}

Node *find_min(Node *node) {
    if (node->left == NULL) {
        return node;
    }
    return find_min(node->left);
}

Node *find_max(Node *node) {
    if (node->right == NULL) {
        return node;
    }
    return find_min(node->right);
}

int find_size(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return find_size(node->left) + find_size(node->right) + 1;
}

Node *delete_node(Node *node, int key) {
    if (node == NULL) {
        return node;
    }

    if (key < node->key) {
        node->left = delete_node(node->left, key);
        return node;
    }
    if (key > node->key) {
        node->right = delete_node(node->right, key);
        return node;
    }

    if (node->left == NULL && node->right == NULL) {
        return NULL;
    }
    if(node->left == NULL) {
        Node *temp = node->right;
        free(node);
        return temp;
    }
    if(node->right == NULL) {
        Node *temp = node->left;
        free(node);
        return temp;
    }
    Node *successor = find_max(node);
    node->key = successor->key;
    node = delete_node(node->right, successor->key);
    return node;
}

int delete_ascending(Node **root) {
    Node *min = find_min(*root);
    int deleted_value = min->key;
    *root = delete_node(*root, min->key);
    return deleted_value;
}

int main() {
    Node *root = NULL;
    root = insert_node(root, 15);
    root = insert_node(root, 5);
    root = insert_node(root, 8);
    root = insert_node(root, 9);
    root = insert_node(root, 10);
    root = insert_node(root, 12);
    root = insert_node(root, 14);
    root = insert_node(root, 17);
    root = insert_node(root, 20);
    root = insert_node(root, 22);
    root = insert_node(root, 25);
    root = insert_node(root, 30);

    int tree_size = find_size(root);

    int arr[tree_size];
    for (int i = 0; i < tree_size; i++) {
        arr[i] = delete_ascending(&root);
    }

    printf("Output Array :\t");
    for (int i = 0; i < tree_size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
