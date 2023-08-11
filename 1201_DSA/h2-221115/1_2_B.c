#include <stdio.h>

void print_int_array(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 20, 30, 40 ,50} ;
    int array_length = sizeof(arr) / sizeof(int);

    int to_be_inserted;
    printf("Enter the number to be inserted: ");
    scanf("%d", &to_be_inserted);

    int location = 0;
    printf("%d\n", location);
    for(int i = array_length - 1; i >= 0; i--) {
        if(to_be_inserted > arr[i]) {
            location = i + 1;
            break;
        }
    }

    printf("%d\n", location);


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