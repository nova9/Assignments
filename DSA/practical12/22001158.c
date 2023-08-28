#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *array, int length) {
    int number_of_comparisons = 0;
    int number_of_shifts = 0;

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            number_of_comparisons++;
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                number_of_shifts++;
            }
        }
    }

    printf("Comparisons = %d\n", number_of_comparisons);
    printf("Shifts = %d\n", number_of_shifts);
}

void insertionSort(int *array, int length) {
    int number_of_comparisons = 0;
    int number_of_shifts = 0;

    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] < key) {
            number_of_comparisons++;
            array[j + 1] = array[j];
            number_of_shifts++;
            j--;
        }
        array[j + 1] = key;
        number_of_shifts++;
    }

    printf("Comparisons = %d\n", number_of_comparisons);
    printf("Shifts = %d\n", number_of_shifts);
}

int main() {
    printf("--- Bubble sort ---\n");
    int array[] = {43, 17, 29, 8, 56, 32, 41};
    int array_length = sizeof(array) / sizeof(int);

    bubbleSort(array, array_length);
    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    printf("--- Insertion sort ---\n");
    int array2[] = {43, 17, 29, 8, 56, 32, 41};
    int array2_length = sizeof(array) / sizeof(int);

    insertionSort(array2, array2_length);

    for (int i = 0; i < array2_length; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

}