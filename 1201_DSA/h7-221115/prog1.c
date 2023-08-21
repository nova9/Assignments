#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

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

void insert_node(Node **node, int key) {
    if (*node == NULL) {
        Node *new_node = create_node(key);
        *node = new_node;
        return;
    }

    if (key < (*node)->key) {
        insert_node(&(*node)->left, key);
    } else {
        insert_node(&(*node)->right, key);
    }
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

void delete_node(Node **node, int key) {
    if (*node == NULL) {
        printf("Not Found\n");
    } else if (key < (*node)->key) {
        delete_node(&(*node)->left, key);
    } else if (key > (*node)->key) {
        delete_node(&(*node)->right, key);
    } else if ((*node)->left && (*node)->right) {
        Node *temp = find_max((*node)->left);
        (*node)->key = temp->key;
        delete_node(&(*node)->left, temp->key);
    } else {
        Node *temp = *node;
        if ((*node)->left == NULL && (*node)->right == NULL) {
            *node = NULL;
        } else if ((*node)->left != NULL) {
            *node = (*node)->left;
        } else {
            *node = (*node)->right;
        }
        free(temp);
    }
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

int find_size(Node *node) {
    if (node == NULL) {
        return 0;
    }

    return find_size(node->left) + find_size(node->right) + 1;
}

void mirror(Node *node) {
    if (node != NULL) {
        mirror(node->left);
        mirror(node->right);
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void view(Node *node) {

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
        insert_node(&root, number);
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