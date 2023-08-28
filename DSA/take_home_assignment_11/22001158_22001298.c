#include <stdio.h>
#include <stdlib.h>

typedef struct User {
    char *name;
    int age;
    int nof; // nuber of followers
} User;

typedef struct Node Node;
struct Node {
    User *user;
    Node *left;
    Node *right;
};

void print_inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    print_inorder(node->left);
    printf("%s, %d, %d      ", node->user->name, node->user->age, node->user->nof);
    print_inorder(node->right);
}

User *create_user(char *name, int age, int nof) {
    User *new_user = malloc(sizeof(User));
    new_user->name = name;
    new_user->age = age;
    new_user->nof = nof;

    return new_user;
}

Node *create_node(User *user) {
    Node *new_node = malloc(sizeof(Node));
    new_node->user = user;
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

Node *insert(Node *node, User *user) {
    if (node == NULL)
        return create_node(user);

    if (user->nof < node->user->nof) {
        node->left = insert(node->left, user);
    } else if (user->nof > node->user->nof) {
        node->right = insert(node->right, user);
    } else {
        return node;
    }

    int balance_factor = get_balance_factor(node);

    if (balance_factor > 1 && user->nof < node->left->user->nof)
        return right_rotate(node);

    if (balance_factor < -1 && user->nof > node->right->user->nof)
        return left_rotate(node);

    if (balance_factor > 1 && user->nof > node->left->user->nof) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance_factor < -1 && user->nof < node->right->user->nof) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

Node *delete(Node *node, User *user) {
    if (node == NULL)
        return node;

    if (user->nof < node->user->nof)
        node->left = delete(node->left, user);

    else if (user->nof > node->user->nof)
        node->right = delete(node->right, user);

    else {
        if ((node->left == NULL) || (node->right == NULL)) {
            Node *temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else
                *node = *temp;

            free(temp);
        } else {
            Node *temp = find_min(node->right);
            node->user = temp->user;
            node->right = delete(node->right, temp->user);
        }
    }

    if (node == NULL)
        return node;

    int balance = get_balance_factor(node);

    if (balance > 1 && get_balance_factor(node->left) >= 0)
        return right_rotate(node);

    if (balance > 1 && get_balance_factor(node->left) < 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && get_balance_factor(node->right) <= 0)
        return left_rotate(node);

    if (balance < -1 && get_balance_factor(node->right) > 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

int main() {
    Node *root = NULL;

    User users[] = {
            {"Alice",   25, 1000},
            {"Bob",     30, 500},
            {"Charlie", 22, 750},
            {"David",   28, 800},
            {"Eve",     29, 1200},
    };
    int users_length = sizeof(users) / sizeof(User);

    for (int i = 0; i < users_length; i++) {
        root = insert(root, &users[i]);}


    root = delete(root, &users[2]);

    print_inorder(root);
    printf("\n");

}