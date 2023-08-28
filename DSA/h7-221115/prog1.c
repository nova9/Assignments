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
    root = insert(root, 5);
    root = insert(root, 45);
    root = insert(root, 3);
    root = insert(root, 100);
    root = insert(root, 1);

    delete_node(&root, 45);

    printf("size = %d\n", find_size(root));
    printf("height = %d\n", find_height(root));
    printf("min = %d\n", find_min(root)->key);
    printf("max = %d\n", find_max(root)->key);

    display(root, INORDER);

    mirror(root);

    display(root, INORDER);
}