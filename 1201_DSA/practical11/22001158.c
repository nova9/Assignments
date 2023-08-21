#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

typedef enum TraverseType {
    PREORDER,
    INORDER,
    POSTORDER,

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

void print_tree(Node *tree, int indent) {
    if (tree != NULL) {
        print_tree(tree->right, indent + 5);
        for (int i = 0; i < indent; i++)
            printf(" ");
        printf("%d\n", tree->key);
        print_tree(tree->left, indent + 5);
    }
}

int get_balance_factor(Node *node) {
    return find_height(node->left) - find_height(node->right);
}

Node *right_rotate(Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node *left_rotate(Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
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
    while (1) {
        char input[300];
        printf("Current tree: \n");
        print_tree(root, 0);
        printf("Enter a value to insert: ");
        scanf("%s", input);

        errno = 0;
        int number = strtol(input, NULL, 10);
        if (errno != 0) {
            break;
        }
        root = insert(root, number);
    }

//    delete_node(&root, 71);

    printf("size = %d\n", find_size(root));
    printf("height = %d\n", find_height(root));

//    display(root, INORDER);

//    mirror(root);
//
//    display(root, INORDER);

//    print_tree(root, 0);
}