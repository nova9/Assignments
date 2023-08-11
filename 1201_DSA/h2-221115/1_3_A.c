#include <stdio.h>

void print_int_array(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int array_length;
    printf("Enter array size: ");
    scanf("%d", &array_length);

    int arr[array_length];
    printf("Enter the array: ");
    for(int i = 0; i < array_length; i++) {
        scanf("%d", &arr[i]);
    }

    int location;
    printf("Enter the index of the location to delete: ");
    scanf("%d", &location);

    for(int i = location; i < array_length; i++) {
        arr[i] = arr[i + 1];
    }

    print_int_array(arr, array_length - 1);
}