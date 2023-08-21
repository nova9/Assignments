#include <stdio.h>

int main() {
    int number_of_numbers = 10;
    float numbers[number_of_numbers];
    for (int i = 0; i < number_of_numbers; ++i) {
        printf("Enter number %d:", i);
        scanf("%f", &numbers[i]);
    }

    int amount = 0;
    float distinct[number_of_numbers];

    for (int i = 0; i < number_of_numbers; i++) {
        int skip = 0;
        for (int j = 0; j < amount; j++) {
            if (distinct[j] == numbers[i]) {
                skip = 1;
                break;
            }
        }
        if (skip) {
            continue;
        }
        distinct[amount] = numbers[i];
        amount++;
    }

    printf("Amount of distinct numbers: %d\n", amount);

    for (int i = 0; i < amount; i++) {
        printf("%f\n", distinct[i]);
    }
}