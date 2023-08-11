#include <stdio.h>

int main() {
    printf("How many elements in the array: ");
    int length;
    scanf("%d", &length);

    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("Enter element for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            int a = *(arr + j);
            int b = *(arr + j + 1);
            if (a > b) {
                *(arr + j) = b;
                *(arr + j + 1) = a;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}