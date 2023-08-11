#include <stdio.h>

int main() {
    char alphabet[26 * 2];

    for (int i = 0; i < 26; i++) {
        *(alphabet + i) = 'a' + i;
    }

    for (int i = 0; i < 26; i++) {
        *(alphabet + i + 26) = 'A' + i;
    }

    for (int i = 0; i < 26 * 2; i++) {
        printf("%c ", *(alphabet + i));
    }
    printf("\n");
}