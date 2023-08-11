#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/list.h"

void concatenate(List *list1, List *list2) {
    ListNode *list1_tail = traverse(list1, get_length(list1) - 1);
    ListNode *list2_head = traverse(list2, 0);

    list1_tail->next = list2_head;
    list2_head->prev = list1_tail;
}

char *get_string() {
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while (EOF != (ch = getchar()) && ch != '\n') {
        str[len++] = ch;
        if (len == size) {
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

List *get_list(const char *message) {
    printf("%s", message);
    char *elements_string = get_string();

    int *numbers = malloc(sizeof(int));
    int numbers_length = 0;

    char *latest_number_string = malloc(sizeof(char));
    latest_number_string[0] = '\0';
    for (int i = 0; i < strlen(elements_string) + 1; ++i) {
        char character_string[2] = {elements_string[i], '\0'};
        if(elements_string[i] == ' ' || elements_string[i] == '\0') {
            int latest_number = strtol(latest_number_string, NULL, 10);
            latest_number_string = malloc(sizeof(char));
            latest_number_string[0] = '\0';

            numbers = realloc(numbers, sizeof(int) * (numbers_length + 1));
            numbers[numbers_length++] = latest_number;
        } else {
            strcat(latest_number_string, character_string);
        }
    }

    List *list = init_list(numbers, numbers_length);

    return list;
}

int main() {
    List *list1 = get_list("Enter values for list 1 seperated by spaces: ");

    List *list2 = get_list("Enter values for list 2 seperated by spaces: ");

    printf("List 1:   ");
    display_list(list1);

    printf("List 2:   ");
    display_list(list2);

    concatenate(list1, list2); // list2 is concatenated to list 1

    printf("Concatenated:   ");
    display_list(list1);
}