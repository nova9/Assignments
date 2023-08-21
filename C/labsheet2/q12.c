#include <stdio.h>

int main() {
    printf("Temperature in Celsius: ");
    float celsius;
    scanf("%f", &celsius);

    printf("Temperature in fahrenheit: %f\n", celsius * 9 / 5 + 32);
}