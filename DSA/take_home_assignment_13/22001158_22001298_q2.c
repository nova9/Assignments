#include <stdio.h>

void merge(int *array, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = array[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

void print_array(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {-5, 3, -2,3, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    print_array(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    print_array(arr, arr_size);
}