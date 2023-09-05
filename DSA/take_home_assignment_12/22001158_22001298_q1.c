#include <stdio.h>

void bubbleSort(int *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp_j = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp_j;
            }
        }
    }
}

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {250, 150, 350, 200, 300};

    int length = sizeof(array) / sizeof(int);

    bubbleSort(array, length);
    printArray(array, length);
}