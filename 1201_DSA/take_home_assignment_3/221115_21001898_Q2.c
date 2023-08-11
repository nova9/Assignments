#include <stdio.h>

int main() {
	int arr[] = {20, 40, 4, 55, 30};
	int length = sizeof(arr) / sizeof(int);

start:
	printf("Enter an element to delete: ");
	int value_to_delete;
	scanf("%d", &value_to_delete);


	int index_to_delete = -1;
	for(int i = 0; i < length; i++) {
		if(arr[i] == value_to_delete) {
			index_to_delete = i;
			break;
		}
	}

	if(index_to_delete == -1) {
		printf("%d is not in the array. Try again.\n", value_to_delete);
		goto start;
	}

	for(int i = index_to_delete; i < length - 1; i++) {
		arr[i] = arr[i + 1];
	}

	for(int i = 0; i < length - 1; i++) {
		printf("%d\t", arr[i]);
	}
    printf("\n");

}
