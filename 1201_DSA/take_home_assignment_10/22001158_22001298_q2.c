#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef enum TraverseType {
    PREORDER,
    INORDER,
    POSTORDER
} TraverseType;

void print_preorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d  ", node->data);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print_inorder(node->left);
    printf("%d  ", node->data);
    print_inorder(node->right);
}

void print_postorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d  ", node->data);
}

void display(Node *node, int method) {
    switch (method) {
        case PREORDER:
            print_preorder(node);
            break;
        case INORDER:
            print_inorder(node);
            break;
        case POSTORDER:
            print_postorder(node);
            break;
        default:
            printf("Unknown method");
    }
    printf("\n");
}

Node *insert(Node *node, int data) {
    if (node == NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data <= node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

Node *lca(Node *node, int v1, int v2) {
    if (node == NULL) {
        return node;
    }

    if (v1 < node->data && v2 < node->data) {
        return lca(node->left, v1, v2);
    }

    if (node->data < v1 && node->data < v2) {
        return lca(node->right, v1, v2);
    }

    return node;
}

int main() {
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    int node_array[number_of_nodes];
    for (int i = 0; i < number_of_nodes; i++) {
        scanf("%d", &node_array[i]);
    }

    Node *root = NULL;
    for (int i = 0; i < number_of_nodes; i++) {
        root = insert(root, node_array[i]);
    }

    int v1;
    scanf("%d", &v1);
    int v2;
    scanf("%d", &v2);

    Node *lca_node = lca(root, v1, v2);

    printf("LCA data = %d\t LCA address = %p\n", lca_node->data, lca_node);
}