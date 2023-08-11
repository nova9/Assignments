#include <stdio.h>

int main() {
    float a = 1, b = 2, c = 3, d = 4;

    printf("%f\n", (a + b) / (c + d) ); // 0.428571
    printf("%f\n", a + b / (c + d) ); // 1.285714
    printf("%f\n", (a + b) / c + d ); // 5.000000
    printf("%f\n", a * b / c * d ); // 2.666667
}