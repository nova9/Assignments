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

    float max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    float second_max;
    for (int i = 0; i < n; i++) {
        if(arr[i] != max) {
            second_max = arr[i];
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }

    printf("Second largest number is: %f\n", second_max);
}