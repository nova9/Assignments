#include <stdio.h>

int main() {
    int m = 40;
    int n = 20;
    int o = 20;
    int p = 30;

    printf("%d\n", ( m > n && m != 0 )); // 1
    printf("%d\n", (o > p || p != 20)); // 1
    printf("%d\n", !(m > n && m != 0)); // 0
}