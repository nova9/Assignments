#include <stdio.h>
#include <stdlib.h>

#include "includes/list.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

int main() {
    printf("List is empty enter an integer to insert: ");
    int number;
    scanf("%d", &number);
    int arr[] = {number};
    int length = sizeof(arr) / sizeof(int);

    List *list = init_list(arr, length);

    printf(BLU "List:   ");
    display_list(list);
    printf(RESET);

    while (1) {
        printf("1. Insert\n2. Delete\nChoose(Enter anything else to exit): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter an integer to insert: ");
            int number;
            scanf("%d", &number);
            insert(list, number, 0);
        } else if (choice == 2) {
            if (get_length(list) == 1) {
                printf(RED "Can't delete the last value.\n" RESET);
            } else {
                delete(list, get_length(list) - 1);
            }
        } else {
            exit(0);
        }

        printf(BLU "List:   ");
        display_list(list);
        printf(RESET);
    }
}