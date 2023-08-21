#include <stdio.h>
#include <stdlib.h>

char *get_string() {
    size_t size = 10;
    int ch;
    size_t len = 0;
    char *str = malloc(sizeof(char) * size);
    if (!str) return str;
    while (EOF != (ch = getchar()) && ch != '\n') {
        str[len++] = ch;
        if (len == size) {
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str) return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

int count_vowels(const char *string) {
    int count = 0;
    for (int i = 0; 1; i++) {
        char c = *(string + i);
        if (c == '\0') {
            return count;
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
}

int count_consonants(const char *string) {
    int count = 0;
    for (int i = 0; 1; i++) {
        char c = *(string + i);
        if (c == '\0') {
            return count;
        }
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
                count++;
            }
        }
    }
}

int main() {
    printf("Enter a string: ");
    char *str = get_string();

    printf("number of vowels = %d\n", count_vowels(str));
    printf("number of consonants = %d\n", count_consonants(str));
}
