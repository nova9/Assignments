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

int string_length(const char *string) {
    int length = 0;
    for (int i = 0; 1; i++) {
        if (string[i] == '\0') {
            return length;
        }
        length++;
    }
}

int main() {
    printf("Enter a string: ");
    char *str = get_string();

    printf("length = %d\n", string_length(str));
}
