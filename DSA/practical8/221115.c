#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node *next;
};

Node *addToEmpty(Node *last, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node;

    last = new_node;
    return last;
}

struct Node *insertAtEnd(Node *last, int data) {
    if (last == NULL) {
        return addToEmpty(last, data);
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = last->next;
    last->next = new_node;

    return new_node;
}

Node *deleteAtBegin(Node *last) {
    if (last == last->next) {
        return NULL;
    }
    Node *first = last->next;
    last->next = first->next;
    free(first);
    return last;
}

char *isCircularTwin(char *string) {
        int string_length = strlen(string);

	Node *string_list = NULL;
	for(int i = 0; i < string_length; i++) {
		if (i < string_length / 2) {
			string_list = insertAtEnd(string_list, string[i]);
		} else if (string[i] == string_list->next->data) {
			string_list = deleteAtBegin(string_list);
		}
	}

        return string_list == NULL ? "Circular Twin" : "Not Circulat Twin";
}

int main() {
	printf("Enter a word, \n\t* No longer than 299 letters\n\t* No spaces \n: ");
        char string[300];
        scanf("%s", string);

        printf("%s\n", isCircularTwin(string));
    	
}
