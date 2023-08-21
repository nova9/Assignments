#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
    char data;
    Node *next;
};

Node *insert(Node *head, int index, char data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    if (index == 0) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("The position is beyond the length of the list.\n");
        free(new_node);
        return head;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}

char *isCircularTwin(char *string) {
        int string_length = strlen(string);

        char left_string[150];
        char right_string[150];

        for(int i = 0; i < string_length / 2; i++) {
                left_string[i] = string[i];
        }
        left_string[string_length / 2] = '\0';

        for(int i = 0; i < string_length / 2; i++) {
                right_string[i] = string[string_length / 2 + i];
        }
        right_string[string_length / 2] = '\0';

        bool isCircularTwin = true;
        for(int i = 0; i < string_length / 2; i++) {
                if (left_string[i] != right_string[i])
                        isCircularTwin = false;
        }

        return isCircularTwin ? "Circular Twin" : "Not Circulat Twin";
}

int main() {
	printf("Enter a word, \n\t* No longer than 299 letters\n\t* No spaces \n: ");
	char string[300];
	scanf("%s", string);

	printf("%s\n", isCircularTwin(string));

}
