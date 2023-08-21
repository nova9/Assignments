#include <stdio.h>

int main() {
    printf("Enter the amount of numbers: ");
    int n;
    scanf("%d", &n);

    float arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    float min = arr[0];
    for(int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int position;
    for(int i = 0; i < n; i++) {
        if (arr[i] == min) {
            position = i;
        }
    }

    printf("Index of the smallest number: %d\n", position);
}