#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void insertionSort(int *array, int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j - 1]) {
                int temp_j = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp_j;
            } else {
                break;
            }
        }
    }
}

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

int largest(int *arr, int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void lis_length(int *array, int length) {
    int list[length];
    for (int i = 0; i < length; i++) {
        list[i] = 1;
    }

    for (int i = length - 1; i >= 0; i--) {
        for (int j = i; j < length; j++) {
            if (array[i] < array[j]) {
                list[i] = MAX(list[i], 1 + list[j]);
            }
        }
    }

    printf("LIS = %d\n", largest(list, length));
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

//    insertionSort(array, length);
//    bubbleSort(array, length);
//    printArray(array, length);

//    lis(array, length);
}