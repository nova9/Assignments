#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert(Node **node, int val) {
    if (*node == NULL) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = val;
        new_node->left = new_node->right = NULL;
        *node = new_node;
        return;
    }

    if (val < (*node)->data) {
        insert(&(*node)->left, val);
    } else {
        insert(&(*node)->right, val);
    }
}

void in_order(Node *node) {
    if (node == NULL) {
        return;
    }
    in_order(node->left);
    printf("%d ", node->data);
    in_order(node->right);
}

Node *search(Node *node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (data > node->data) {
        return search(node->right, data);
    } else {
        return search(node->left, data);
    }
}

Node *find_max(Node *node) {
    if (node->right == NULL) {
        return node;
    }

    return find_max(node->right);
}

Node *find_min(Node *node) {
    if (node->left == NULL) {
        return node;
    }

    return find_min(node->left);
}

void delete(Node **node, int val) {
    if (node == NULL) {
        printf("Not Found\n");
    } else if (val < (*node)->data) {
        delete(&(*node)->left, val);
    } else if (val > (*node)->data) {
        delete(&(*node)->right, val);
    } else if ((*node)->left && (*node)->right) {
        Node *temp = find_max((*node)->left);
        (*node)->data = temp->data;
        delete(&(*node)->left, temp->data);
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

int height(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int left_height = height(node->left);
    int right_height = height(node->right);

    if (left_height > right_height) {
        return left_height + 1;
    } else {
        return right_height + 1;
    }
}

int number_of_nodes(Node *node) {
    if (node == NULL) {
        return 0;
    }

    return number_of_nodes(node->left) + number_of_nodes(node->right) + 1;
}

int number_of_internal_nodes(Node *node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 0;
    }

    return number_of_internal_nodes(node->left) + number_of_internal_nodes(node->right) + 1;
}

int number_of_external_nodes(Node *node) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1;
    }

    return number_of_external_nodes(node->left) + number_of_external_nodes(node->right);
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

void delete_tree(Node *node) {
    if (node != NULL) {
        delete_tree(node->left);
        delete_tree(node->right);
        free(node);
    }
}

int main () {
    Node *root = NULL;

    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 2);
    insert(&root, 5);

    printf("height = %d\n", height(root));
    printf("number of nodes = %d\n", number_of_nodes(root));
    printf("number of internal nodes = %d\n", number_of_internal_nodes(root));
    printf("number of external nodes = %d\n", number_of_external_nodes(root));
    printf("min = %d\n", find_min(root)->data);
    printf("max = %d\n", find_max(root)->data);

    mirror(root);
    in_order(root);
}