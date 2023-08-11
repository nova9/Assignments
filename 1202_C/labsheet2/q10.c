#include <stdio.h>

int main() {
    printf("Enter the number of years: ");

    float years;
    scanf("%f", &years);

    printf("Enter the number of days: ");

    float days;
    scanf("%f", &days);

    printf("Minutes = %f\n", (years * 365 + days) * 24 * 60);
}