#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lis(int *array, int length) {
    int lis[length];
    for (int i = 0; i < length; i++) {
        lis[i] = 1;
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (array[j] < array[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    lis(arr, n);
    return 0;
}