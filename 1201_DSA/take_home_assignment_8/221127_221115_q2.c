#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    char character;
    Node *next;
};

bool isSwapInvariant(Node *head) {
    Node *last = head;
    while (last->next != head)
        last = last->next;

    return last->character == head->character;
}

void insertCharacter(Node **head, char ch) {
    Node *newNode = malloc(sizeof(Node));
    newNode->character = ch;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node *last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = newNode;
        newNode->next = *head;
    }
}

void printList(Node *head) {
    Node *current = head;
    if (head != NULL) {
        do {
            printf("%c ", current->character);
            current = current->next;
        } while (current != head);
    } else {
        printf("Empty");
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    printf("Enter a word: ");
    char input[300];
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        insertCharacter(&head, input[i]);
    }

    isSwapInvariant(head) ? printf("Swap Invariant") : printf("Not Swap Invariant");
    printf("\n");
}