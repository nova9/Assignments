#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int coeff;
    int exp;
    Node *next;
};

void display_list(Node *head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    for (Node *i = head; i != NULL; i = i->next) {
        printf("%+dx^%d ", i->coeff, i->exp);
    }

    printf("\n");
}

Node *insert(Node *head, int coeff, int exp) {
    Node *new_node = malloc(sizeof(Node));
    new_node->exp = exp;
    new_node->coeff = coeff;
    new_node->next = NULL;

    Node *last_node = head;
    for (Node *current = head; current != NULL; current = current->next) {
        last_node = current;
    }

    if (last_node == NULL) {
        return new_node;
    }

    last_node->next = new_node;
    return head;
}

Node *addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;

    for (
            struct { Node *poly1; Node *poly2; } s = { poly1, poly2 };
            s.poly1 != NULL || s.poly2 != NULL;
            NULL
            ) {
        if (s.poly1 == NULL) {
            result = insert(result, s.poly2->coeff, s.poly2->exp);
            s.poly2 = s.poly2->next;
        }

        if (s.poly2 == NULL) {
            result = insert(result, s.poly1->coeff, s.poly1->exp);
            s.poly1 = s.poly1->next;
        }

        if (s.poly1 != NULL && s.poly2 != NULL) {
            if (s.poly1->exp > s.poly2->exp) {
                result = insert(result, s.poly1->coeff, s.poly1->exp);
                s.poly1 = s.poly1->next;
            } else if (s.poly1->exp < s.poly2->exp) {
                result = insert(result, s.poly2->coeff, s.poly2->exp);
                s.poly2 = s.poly2->next;
            } else {
                result = insert(result, s.poly1->coeff + s.poly2->coeff, s.poly1->exp);
                s.poly1 = s.poly1->next;
                s.poly2 = s.poly2->next;
            }
        }
    }

    return result;
}

Node *subtractPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;

    for (
            struct { Node *poly1; Node *poly2; } s = { poly1, poly2 };
            s.poly1 != NULL || s.poly2 != NULL;
            NULL
            ) {
        if (s.poly1 == NULL) {
            result = insert(result, s.poly2->coeff, s.poly2->exp);
            s.poly2 = s.poly2->next;
        }

        if (s.poly2 == NULL) {
            result = insert(result, s.poly1->coeff, s.poly1->exp);
            s.poly1 = s.poly1->next;
        }

        if (s.poly1 != NULL && s.poly2 != NULL) {
            if (s.poly1->exp > s.poly2->exp) {
                result = insert(result, s.poly1->coeff, s.poly1->exp);
                s.poly1 = s.poly1->next;
            } else if (s.poly1->exp < s.poly2->exp) {
                result = insert(result, s.poly2->coeff, s.poly2->exp);
                s.poly2 = s.poly2->next;
            } else {
                result = insert(result, s.poly1->coeff - s.poly2->coeff, s.poly1->exp);
                s.poly1 = s.poly1->next;
                s.poly2 = s.poly2->next;
            }
        }
    }

    return result;
}

int main() {
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    poly1 = insert(poly1, 7, 3);
    poly1 = insert(poly1, 3, 2);
    poly1 = insert(poly1, 2, 1);
    poly1 = insert(poly1, 1, 0);

    poly2 = insert(poly2, 1, 2);
    poly2 = insert(poly2, 2, 1);
//    poly2 = insert(poly2, 3, 0);

    printf("Polynomial 1: ");
    display_list(poly1);

    printf("Polynomial 2: ");
    display_list(poly2);

    Node *sum = addPolynomials(poly1, poly2);
    printf("After addition: ");
    display_list(sum);

    Node *difference = subtractPolynomials(poly1, poly2);
    printf("After subtraction: ");
    display_list(difference);
}