#include <stdio.h>

int main() {
    printf("Read n number of values in an array and display it in reverse order:\n");
    printf("--------------------------------------------------------------------\n");

    printf("Input the number of elements to store in the array: ");
    int number_of_elements;
    scanf("%d", &number_of_elements);

    printf("Input %d number of elements in the array: \n", number_of_elements);

    int elements[number_of_elements];
    for(int i = 0; i < number_of_elements; i++) {
        printf("element - %d: ", i);
        scanf("%d", &elements[i]);
    }

    printf("The values stored in the array are:\n");
    for(int i = 0; i < number_of_elements; i++) {
        printf("\t%d", elements[i]);
    }
    printf("\n");

    printf("The values stored in the array in reverse are:\n");
    for(int i = 0; i < number_of_elements; i++) {
        printf("\t%d", elements[number_of_elements - 1 - i]);
    }
    printf("\n");
}
