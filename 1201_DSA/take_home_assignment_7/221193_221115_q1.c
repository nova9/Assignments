#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct Node Node;
struct Node {
    int id;
    char *name;
    float gpa;
    Node *next;
};

Node *initList() {
    return NULL;
}

void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("\t\tID: %d, Name: %s, GPA: %f\n", current->id, current->name, current->gpa);
        current = current->next;
    }
    printf("\n");
}

Node *sortById(struct Node *head) {
    int list_length = 0;
    for (Node *i = head; i != NULL; i = i->next) {
        list_length++;
    }

    for (int j = 0; j < list_length; j++) {
        Node *prev = NULL;
        for (Node *i = head; i->next != NULL; NULL) {
            Node *a = i;
            Node *b = i->next;
            Node *c = i->next->next;
            if (a->id > b->id) {
                if (prev == NULL) {
                    head = b;
                    b->next = a;
                    a->next = c;
                } else {
                    prev->next = b;
                    b->next = a;
                    a->next = c;
                }
                i = a;
                prev = b;
            } else {
                i = b;
                prev = a;
            }
        }
    }

    return head;
}


Node *addStudent(Node *head, int index, int id, char *name, float gpa) {
    Node *new_node = malloc(sizeof(Node));
    new_node->id = id;
    new_node->name = name;
    new_node->gpa = gpa;

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

    head = sortById(head);
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

bool deleteStudent(Node **head, int id) {
    int index = 0;
    bool success = false;
    for (Node *i = *head; i != NULL; i = i->next) {
        if (i->id == id) {
            *head = deleteByIndex(*head, index);
            if (!success) success = true;
        }
        index++;
    }
    return success;
}

char **listToArray(Node *head, int *array_length) {
    int elements_length = 0;
    for (Node *i = head; i != NULL; i = i->next) {
        elements_length++;
    }
    *array_length = elements_length;

    char **elements = calloc(elements_length, sizeof(char *));

    for (struct { Node *i; int j; } s = {head, 0};
            s.i != NULL;
            s.i = s.i->next, s.j++
            ) {
        int id_str_length = s.i->id == 0 ? 1 : log10(s.i->id) + 1;
        char *id_str = malloc(sizeof(char) * (id_str_length + 1));
        sprintf(id_str, "%d", s.i->id);


        int gpa_str_length = 3;
        char gpa_str[gpa_str_length + 1];
        sprintf(gpa_str, "%.1f", s.i->gpa);

        int name_length = strlen(s.i->name);

        char *element_str = malloc(sizeof(char) * (id_str_length + name_length + gpa_str_length + 19 + 1));

        strcat(element_str, "ID: ");
        strcat(element_str, id_str);
        strcat(element_str, ", Name: ");
        strcat(element_str, s.i->name);
        strcat(element_str, ", GPA: ");
        strcat(element_str, gpa_str);

        elements[s.j] = element_str;

        free(id_str);
    }
    return elements;
}


int main() {
    Node *head = initList();

    head = addStudent(head, 0, 1, "Alice", 3.9);
    head = addStudent(head, 1, 2, "Bob", 3.7);
    head = addStudent(head, 2, 3, "Charlie", 3.5);
    head = addStudent(head, 3, 4, "David", 3.6);
    head = addStudent(head, 4, 5, "Eva", 3.8);
    head = addStudent(head, 5, 6, "Frank", 3.1);
    head = addStudent(head, 6, 7, "Grace", 3.4);
    head = addStudent(head, 7, 8, "Hank", 3.3);
    head = addStudent(head, 8, 9, "Ivy", 3.2);
    head = addStudent(head, 9, 10, "Jack", 3.0);

    printf("List after adding: \n");
    displayList(head);

    printf("Delete the 1st Student in the list:\n");
    deleteStudent(&head, 1);
    printf("\tList after deletion: \n");
    displayList(head);

    printf("Delete the Student with the ID: 5 from the list:\n");
    deleteStudent(&head, 5);
    printf("\tList after deletion: \n");
    displayList(head);

    printf("Delete the last Student from the list:\n");
    deleteStudent(&head, 10);
    printf("\tList after deletion: \n");
    displayList(head);

    printf("Delete Student: ID 11\n");
    bool status = deleteStudent(&head, 11);
    if (status) {
        printf("\tList after deletion: \n");
        displayList(head);
    } else {
        printf("\tStatus: Failure, student not found.\n");
    }

    int array_length;
    char **array = listToArray(head, &array_length);

    printf("List to array:\n");
    for (int i = 0; i < array_length; i++) {
        printf("\t\tArray[%d] -> %s\n", i, array[i]);
    }
}