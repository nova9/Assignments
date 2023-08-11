#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Train {
    int trainId;
    char destination[50];
} Train;

typedef struct Node Node;
struct Node {
    Train *train;
    Node *next;
};

Node *insertByIndex(Node *head, Train *train, int index) {
    Node *new_node = malloc(sizeof(Node));
    new_node->train = train;

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

Node *deleteByIndex(Node *head, int index) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("The position is beyond the length of the list.\n");
        return head;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

Node *addTrain(Node *head, int trainId, char *destination) {
    printf("Adding train: ID = %d, Destination = '%s'\n", trainId, destination);
    int list_length = 0;
    for (Node *i = head; i != NULL ; i = i->next) {
        list_length++;
    }

    Train *new_train = malloc(sizeof(Train));
    new_train->trainId = trainId;
    for (int i = 0; i < strlen(destination) + 1; i++) {
        new_train->destination[i] = destination[i];
    }

    head = insertByIndex(head, new_train, list_length);
    return head;
}

Train *departTrain(Node **head) {
    Node first_train_node = **head;
    *head = deleteByIndex(*head, 0);
    return first_train_node.train;
}

Train *nextTrain(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    return head->train;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        printf("%d(%s) ", current->train->trainId, current->train->destination);
        if (current->next != NULL){
            printf("-> ");
        }
        current = current->next;
    }
    printf("\n\n");
}

int main() {
    Node *head = NULL;

    head = addTrain(head, 101, "New York");
    printf("\tCurrent Schedule: ");
    displayList(head);

    head = addTrain(head, 102, "Los Angeles");
    printf("\tCurrent Schedule: ");
    displayList(head);

    head = addTrain(head, 103, "Chicago");
    printf("\tCurrent Schedule: ");
    displayList(head);

    Train *train4 = departTrain(&head);
    printf("Departing train: ID = %d, Destination = '%s'\n", train4->trainId, train4->destination);
    printf("\tCurrent Schedule: ");
    displayList(head);

    Train *train5 = departTrain(&head);
    printf("Departing train: ID = %d, Destination = '%s'\n", train5->trainId, train5->destination);
    printf("\tCurrent Schedule: ");
    displayList(head);

    printf("Next train\n");
    Train *next1 = nextTrain(head);
    if (next1 == NULL) {
        printf("\tCurrent Schedule: Empty\n\n");
    } else {
        printf("\tThe next train is: ID = %d, Destination = '%s'\n\n", next1->trainId, next1->destination);
    }

    Train *train6 = departTrain(&head);
    printf("Departing train: ID = %d, Destination = '%s'\n", train6->trainId, train5->destination);
    printf("\tCurrent Schedule: ");
    displayList(head);
}