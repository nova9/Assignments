#include <stdio.h>
#include <stdlib.h>

int fib (int n) {
    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    printf("%d the fib = %d\n", 5, fib(3));
}