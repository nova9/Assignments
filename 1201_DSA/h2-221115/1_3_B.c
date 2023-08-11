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

    int number;
    printf("Enter the number to delete: ");
    scanf("%d", &number);

    for(int i = 0; i < array_length; i++) {
        if(arr[i] == number) {
            for(int j = i; j < array_length; j++) {
                arr[j] = arr[j + 1];
            }
            array_length--;
            i = 0;
        }
    }

    print_int_array(arr, array_length);
}