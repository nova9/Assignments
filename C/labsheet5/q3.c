#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double sum(double *arr, int length) {
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return sum;
}

double average(double *arr, int length) {
    return sum(arr, length) / length;
}

double minimum(double *arr, int length) {
    double min = arr[0];
    for (int i = 1; i < length; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

double maximum(double *arr, int length) {
    double max = arr[0];
    for (int i = 1; i < length; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void most(double *arr, int length) {
    double unique[length];
    int unique_length = 0;

    for (int i = 0; i < length; i++) {
        bool skip = false;
        for (int j = 0; j < unique_length; j++) {
            if (arr[i] == unique[j]) {
                skip = true;
                break;
            }
        }
        if (skip) {
            continue;
        }
        unique[unique_length] = arr[i];
        unique_length++;
    }

    int *unique_count = calloc(length, sizeof(int));
    for (int i = 0; i < unique_length; i++) {
        for (int j = 0; j < length; j++) {
            if (arr[j] == unique[i]) {
                unique_count[i]++;
            }
        }
    }

    int highest_duplication = unique_count[0];
    for (int i = 0; i < unique_length; i++) {
        if(unique_count[i] > highest_duplication) {
            highest_duplication = unique_count[i];
        }
    }

    int most_indexes_in_unique[unique_length];
    int index_length = 0;
    double most[unique_length];
    for (int i = 0; i < unique_length; i++) {
        if (unique_count[i] == highest_duplication) {
            most_indexes_in_unique[index_length] = i;
            most[index_length] = unique[i];
            index_length++;
        }
    }


    printf("Most occurring: ");
    for (int i = 0; i < index_length; i++) {
        printf("%f   ", most[i]);
    }
    printf("\n");
}

int main() {
    double arr[] = {
            34.5, 56.7, 12.6, 98.4, 54.21, 89.55, 54.2, 98.4, 73.2, 21.45,
            34.5, 98.4, 21.45, 98.4, 9.3
    };
    int length = sizeof(arr) / sizeof(double);

    printf("Sum: %f\n", sum(arr, length));
    printf("Average: %f\n", average(arr, length));
    printf("Minimum: %f\n", minimum(arr, length));
    printf("Maximum: %f\n", maximum(arr, length));
    most(arr, length);
}