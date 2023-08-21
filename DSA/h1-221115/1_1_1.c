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

    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Mean: %f\n", sum / n);
}