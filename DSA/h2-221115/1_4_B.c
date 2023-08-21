#include <stdio.h>
#include <stdlib.h>

void print_int_array(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

struct Array {
    int length;
    int elements[];
};

struct Array *array_merge(struct Array *array_one, struct Array *array_two) {
    struct Array *merged;

    int merged_length = array_one->length + array_two->length;

    merged = malloc(sizeof(struct Array) + sizeof(int) * merged_length);
    merged->length = merged_length;

    for(int i = 0; i < merged->length; i++) {
        if(i < array_one->length) {
            merged->elements[i] = array_one->elements[i];
        } else {
            merged->elements[i] = array_two->elements[i - array_one->length];
        }
    }

    return merged;
}


struct Array *get_array() {
    struct Array *array;

    int array_length;
    printf("What is array length: ");
    scanf("%d", &array_length);

    array = malloc(sizeof(struct Array) + sizeof(int) * array_length);
    array->length = array_length;

    printf("\tEnter elements seperated by spaces: ");
    for(int i = 0; i < array->length; i++) {
        scanf("%d", &array->elements[i]);
    }

    return array;
}

int main() {
    printf("How many arrays: ");
    int number_of_arrays;
    scanf("%d", &number_of_arrays);

    struct Array *last = get_array();
    for(int i = 0; i < number_of_arrays - 1; i++) {
        struct Array *array = get_array();
        last = array_merge(last, array);
    }

    print_int_array(last->elements, last->length);
}