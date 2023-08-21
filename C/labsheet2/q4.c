#include <stdio.h>

int main() {
    char C = 'B';
    int i = 3, j = 3, k = 3;
    double x = 0.0, y = 2.3;

    printf("%s\n", i && j && k ? "true" : "false");
    printf("%s\n", x || i && j - 3 ? "true" : "false");
    printf("%s\n", i < j && x < y ? "true" : "false");
    printf("%s\n", i<j||x<y ? "true" : "false");
    printf("%s\n", 'A' <= C && C <= 'Z' ? "true" : "false");
    printf("%s\n", C - 1 == 'A' || C + 1 == 'Z' ? "true" : "false");
}