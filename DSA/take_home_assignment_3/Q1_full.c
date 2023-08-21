#include <stdio.h>
#include <stdbool.h>

bool in_range(int lower, int upper, int size) {
    return lower <= size && size <= upper;
}

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int get_size() {
    printf("Enter the size: ");

    int size;
    scanf("%d", &size);

    while(!in_range(1, 1000, size)) {
        printf("Size must be between 1 and 1000. Enter the size again: ");
        scanf("%d", &size);
    }

    return size;
}

int main() {
    int size = get_size();


    int v[size];

    printf("Enter values: ");
    get_values:
        for(int i = 0; i < size; i++) {
            int value;
            scanf("%d", &value);
            v[i] = value;

            if(!in_range(1, 1000, value)) {
                printf("Array values must be between 1 and 1000. Enter values again: ");
                clear_stdin();
                goto get_values;
            }
        }

    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += v[i];
    printf("%d\n", sum);
}
