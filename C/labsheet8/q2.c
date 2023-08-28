#include <stdio.h>
#include <stdbool.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

bool is_equal(Date d1, Date d2) {
    if (d1.day != d2.day) {
        return false;
    }

    if (d1.month != d2.month) {
        return false;
    }

    if (d1.year != d2.year) {
        return false;
    }

    return true;
}


int main() {
    Date d1;
    Date d2;

    printf("Enter the first date,\n");
    printf("\tDay: ");
    scanf("%d", &d1.day);
    printf("\tMonth: ");
    scanf("%d", &d1.month);
    printf("\tYear: ");
    scanf("%d", &d1.year);

    printf("Enter the second date,\n");
    printf("\tDay: ");
    scanf("%d", &d2.day);
    printf("\tMonth: ");
    scanf("%d", &d2.month);
    printf("\tYear: ");
    scanf("%d", &d2.year);

    is_equal(d1, d2) ? printf("Dates are equal\n") : printf("Dates are not equal\n");
}