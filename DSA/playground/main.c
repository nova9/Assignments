#include <stdio.h>

void swap(int *a, int *b) {
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

void bubble_sort(int *array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&(array[j]), &(array[j + 1]));
            }
        }
    }
}

void insertion_sort(int *array, int length) {
    for (int i = 1; i < length; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void selection_sort(int *array, int length) {
    for (int i = 0; i < length; i++) {
        int small = array[i];
        int pos = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < small) {
                small = array[j];
                pos = j;
            }
        }
        swap(&(array[i]), &(array[pos]));
    }
}

void selection_sort_recursive (int *array, int length) {
    if (length == 0)
        return;

    int smallest_pos = 0;
    for (int i = 1; i < length; i++) {
        if (array[i] < array[smallest_pos]) {
            smallest_pos = i;
        }
    }

    swap(&(array[smallest_pos]), &(array[length - 1]));

    selection_sort_recursive(array, length - 1);
}

int main() {
    int array[] = {30, 40, 2, 4, 70, 17, 31, 900, 46};
    int length = sizeof(array) / sizeof(int);

//    selection_sort(array, length);
//    bubble_sort(array, length);
    insertion_sort(array, length);
//    selection_sort_recursive(array, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}