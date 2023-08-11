#include <stdio.h>

int main() {
    printf("Copy the elements one array into another array:\n");
    printf("-----------------------------------------------\n");

    printf("Input the number of elements to store in the array: ");
    int number_of_elements;
    scanf("%d", &number_of_elements);

    printf("Input %d number of elements in the array: \n", number_of_elements);

    int elements[number_of_elements];
    for(int i = 0; i < number_of_elements; i++) {
        printf("element - %d: ", i);
        scanf("%d", &elements[i]);
    }

    printf("The elements stored in the first array are:\n");
    for(int i = 0; i < number_of_elements; i++) {
        printf("\t%d", elements[i]);
    }
    printf("\n");

    int copy[number_of_elements];
    for(int i = 0; i < number_of_elements; i++) {
        copy[i] = elements[i];
    }

    printf("The elements copied into the second array are:\n");
    for(int i = 0; i < number_of_elements; i++) {
        printf("\t%d", copy[i]);
    }
    printf("\n");
}