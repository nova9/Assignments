#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string() {
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while(EOF != (ch = getchar()) && ch != '\n'){
        str[len++] = ch;
        if(len == size){
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

int count_vowels(char *string) {
    int string_length = strlen(string);
    int vowel_count = 0;
    for(int i = 0; i < string_length; i++) {
        if (
                string[i] == 'a' || string[i] == 'e' || string[i] == 'a' || string[i] == 'o' || string[i] == 'u' ||
                string[i] == 'A' ||string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'
                ) {
            vowel_count++;
        }
    }

    return vowel_count;
}

int main() {
    printf("Enter a string: ");
    char *string = get_string();

    printf("Number of vowels: %d\n", count_vowels(string));
}
