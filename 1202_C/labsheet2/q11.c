#include <stdio.h>

int main() {
    printf("What is your height in feet and inches: ");

    float feet, inch;
    scanf("%f %f", &feet, &inch);

    printf("Your height in centimeters is: %f\n", (feet * 12 + inch) * 2.54);
}