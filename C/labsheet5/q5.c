#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool length_is_valid(const char *string) {
    return strlen(string) == 8;
}

bool first_letter_is_valid(const char *string) {
    return string[0] == 'S';
}

bool forward_slashes_are_valid(const char *string) {
    int number_of_forward_slashes = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '/') number_of_forward_slashes++;
    }
    return number_of_forward_slashes == 2;
}

bool batch_is_valid(const char *string) {
    bool collect = false;
    char *batch_string = malloc(sizeof(char));
    batch_string[0] = '\0';
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '/') {
            collect = !collect;
            continue;
        }
        if (collect) {
            char char_string[2] = {string[i], '\0'};
            batch_string = realloc(batch_string, sizeof(char) * (strlen(batch_string) + 1 + 1));
            strcat(batch_string, char_string);
        }
    }

    for (int i = 0; i < strlen(batch_string); i++) {
        if (!('0' <= batch_string[i] && batch_string[i] <= '9')) {
            return false;
        }
    }
    return strlen(batch_string) != 0;

}

bool student_number_is_valid(const char *string) {
    char *student_number_string = malloc(sizeof(char));
    student_number_string[0] = '\0';
    for (int i = strlen(string) - 3; i < strlen(string); i++) {
        char char_string[2] = {string[i], '\0'};
        student_number_string = realloc(student_number_string, sizeof(int) * (strlen(student_number_string) + 1 + 1));
        strcat(student_number_string, char_string);
    }

    for (int i = 0; i < strlen(student_number_string); i++) {
        if (!('0' <= student_number_string[i] && student_number_string[i] <= '9')) {
            return false;
        }
    }
    return true;
}

int main() {
    char *registration_numbers[] = {
            "S/09/867",
            "E/08/465",
            "S0967854",
            "S/096/76",
            "S//09475",
            "S//8/564",
            "S/0A/564",
            "S/A9/864",
            "S/09/67H",
            "S@09H4N"
    };

    for (int i = 0; i < 10; ++i) {
        bool everything_is_valid = true;
        printf("----------------------------VALIDATING REGISTRATION NUMBER : %s---------------------------------\n\n", registration_numbers[i]);
        printf("Condition 01: There are exactly 8 characters\n");
        if (length_is_valid(registration_numbers[i])) {
            printf("\t\tThe first condition satisfies\n");
        } else {
            printf("\t\tThe first condition does not satisfy\n");
            everything_is_valid = false;
        }
        printf("\n");

        printf("Condition 02: First letter should be 'S'\n");
        if (first_letter_is_valid(registration_numbers[i])) {
            printf("\t\tThe second condition satisfies\n");
        } else {
            printf("\t\tThe second condition does not satisfy\n");
            everything_is_valid = false;
        }
        printf("\n");

        printf("Condition 03: There should be exactly two '/'s \n");
        if (forward_slashes_are_valid(registration_numbers[i])) {
            printf("\t\tThe third condition satisfies\n");
        } else {
            printf("\t\tThe third condition does not satisfy\n");
            everything_is_valid = false;
        }
        printf("\n");

        printf("Condition 04: The batch is represented by two digits in between two '/'s \n");
        if (batch_is_valid(registration_numbers[i])) {
            printf("\t\tThe fourth condition satisfies\n");
        } else {
            printf("\t\tThe fourth condition does not satisfy\n");
            everything_is_valid = false;
        }
        printf("\n");

        printf("Condition 05: Last three digits immediately after the second slash represents the student number \n");
        if (student_number_is_valid(registration_numbers[i])) {
            printf("\t\tThe fifth condition satisfies\n");
        } else {
            printf("\t\tThe fifth condition does not satisfy: No integer representation\n");
            everything_is_valid = false;
        }
        printf("\n");

        if (everything_is_valid) {
            printf("\n---------------------------------THE REGISTRATION NUMBER IS VALID-------------------------------------\n\n");
        } else {
            printf("\n------------------------------THE REGISTRATION NUMBER IS NOT VALID-----------------------------------\n\n");

        }
    }
}