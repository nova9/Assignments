#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    char character;
    Node *prev;
    Node *next;
};

bool isPalindrome(Node *head) {
    Node *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    while (head != last_node) {
        if (head->character != last_node->character) {
            return false;
        }
        head = head->next;
        last_node = last_node->prev;
    }
    return true;
}

void insertCharacter(Node **head, char ch) {
    if (*head != NULL) {
        Node *last_node = *head;
        while (last_node->next != NULL) { // null doesnt have next
            last_node = last_node->next;
        }

        Node *new_node = malloc(sizeof(Node));
        new_node->character = ch;
        new_node->next = NULL;
        new_node->prev = last_node;

        last_node->next = new_node;
    } else {
        Node *new_node = malloc(sizeof(Node));
        new_node->character = ch;
        new_node->next = NULL;
        new_node->prev = NULL;

        *head = new_node;
    }

}

void printList(Node *node) {
    while (node != NULL) {
        printf("%c ", node->character);
        node = node->next;
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

    isPalindrome(head) ? printf("Palindrome") : printf("Not a palindrome");
    printf("\n");
}