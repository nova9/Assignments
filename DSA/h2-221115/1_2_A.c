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

    int to_be_inserted;
    printf("Enter the number to be inserted: ");
    scanf("%d", &to_be_inserted);

    int location;
    printf("Enter the index of the location to insert: ");
    scanf("%d", &location);


    int new_arr[array_length + 1];
    for(int i = 0; i < array_length + 1; i++) {
        if(i == location) {
            new_arr[i] = to_be_inserted;
        } else if(i > location) {
            new_arr[i] = arr[i - 1];
        } else {
            new_arr[i] = arr[i];
        }
    }

    printf("New Array: ");
    print_int_array(new_arr, array_length + 1);
}