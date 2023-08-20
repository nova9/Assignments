#include <stdio.h>
#include <stdlib.h>

typedef enum TraverseType {
    PREORDER,
    INORDER,
    POSTORDER
} TraverseType;

typedef struct Node Node;
struct Node {
    int key;
    Node *left;
    Node *right;
};

void print_preorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d  ", node->key);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print_inorder(node->left);
    printf("%d  ", node->key);
    print_inorder(node->right);
}

void print_postorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d  ", node->key);
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

Node *create_node(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert_node__(Node *node, int key) {
    if (node == NULL) {
        return create_node(key);
    }
    if (key > node->key) {
        node->right = insert_node__(node->right, key);
    } else {
        node->left = insert_node__(node->left, key);
    }
    return node;
}

void insert_node(Node **node, int key) {
    *node = insert_node__(*node, key);
}

Node *search_node(Node *node, int key) {
    if (node->key == key) {
        return node;
    }
    if (key > node->key) {
        return search_node(node->right, key);
    } else {
        return search_node(node->left, key);
    }
}

Node *find_min(Node *node) {
    if (node == NULL) {
        return NULL;
    } else if (node->left == NULL) {
        return node;
    }
    return find_min(node->left);
}

Node *find_max(Node *node) {
    if (node != NULL) {
        while (node->right != NULL) {
            node = node->right;
        }
    }
    return node;
}

Node *delete_node__(Node *node, int key) {
    if (node == NULL) {
        printf("Key not found\n");
        return node;
    }

    if (key < node->key) {
        node->left = delete_node__(node->left, key);
        return node;
    } else if (key > node->key) {
        node->right = delete_node__(node->right, key);
        return node;
    }

    if (node->left == NULL && node->right == NULL) {
        return NULL;
    } else if (node->left == NULL) {
        Node *temp = node->right;
        free(node);
        return temp;
    } else if (node->right == NULL) {
        Node *temp = node->left;
        free(node);
        return temp;
    } else {
        Node *successor = find_min(node->right);
        node->key = successor->key;
        node->right = delete_node__(node->right, successor->key);
        return node;
    }
}

void delete_node(Node **root, int key) {
    *root = delete_node__(*root, key);
}

int main() {
    Node *root = NULL;
    insert_node(&root, 3);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 11);
    insert_node(&root, 15);
    insert_node(&root, 6);
    insert_node(&root, 8);
    insert_node(&root, 14);
    insert_node(&root, 16);
    insert_node(&root, 1);

    delete_node(&root, 71);

    display(root, INORDER);
}