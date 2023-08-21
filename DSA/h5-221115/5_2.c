#include <stdio.h>
#include <stdlib.h>

#include "includes/list.h"

void insert_sorted(List *list, int value) {
    for (int i = get_length(list) - 1; i >= 0; i--) {
        if (traverse(list, i)->value < value) {
            insert(list, value, i + 1);
            return;
        }
    }
    insert(list, value, 0);
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

int get_input() {
    printf("Enter an integer to insert (Enter a letter to exit): ");
    char *input_string = get_string();

    char *endptr;
    int input = strtol(input_string, &endptr, 10);
    if (endptr == input_string) {
        exit(0);
    }

    return input;
}

int main() {
    int input = get_input();

    int arr[] = {input};
    int length = sizeof(arr) / sizeof(int);

    List *list = init_list(arr, length);

    printf("List :   ");
    display_list(list);

    while (1) {
        insert_sorted(list, get_input());
        display_list(list);
    }
}