#include <stdio.h>

int int_pow(int base, int exponent) {
    int power = 1;
    for(int i = 0; i < exponent; i++) {
        power = power * base;
    }
    return power;
}

int main() {
    printf("Enter the amount of numbers: ");
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int number = 0;
    for(int i = 0; i < n; i++) {
        number = number + (arr[i] * int_pow(10, n - i - 1));
    }

    printf("Number: %d\n", number);
}