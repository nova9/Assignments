#include <stdio.h>

int main() {
    int n;
    float x;

    printf("Enter X: ");
    scanf("%f", &x);

    printf("Enter N: ");
    scanf("%d", &n);

    float power = 1;
    for(int i = 0; i < n; i++) {
        power *= x;
    }

    printf("X^N = %f\n", power);
}