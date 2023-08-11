#include <stdio.h>

void calc_factorial(int num, int *factorial) {
    int i;

    *factorial = 1;

    for (i = 1; i <= num; i++)
        *factorial = *factorial * i;
}

int main() {
    printf("Enter an integer to find the factorial: ");
    int number;
    scanf("%d", &number);

    int factorial;
    calc_factorial(number, &factorial);

    printf("factorial = %d\n", factorial);
}