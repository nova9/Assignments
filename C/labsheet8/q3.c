#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

bool is_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int how_many_days(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

void print_date(Date date) {
    printf("Day: %d\n", date.day);
    printf("Month: %d\n", date.month);
    printf("Year: %d\n", date.year);
}

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Date now = {tm.tm_mday,  tm.tm_mon + 1, tm.tm_year + 1900};

    print_date(now);

    int excess_days = 45 - 2;
    while (excess_days != 0) {
        if (now.day + excess_days > how_many_days(now.month, now.year)) {
            excess_days -= how_many_days(now.month, now.year) - now.day ;
            now.month++;
            now.day = 1;
        } else {
            now.day += excess_days;
            excess_days = 0;
        }
    }


    print_date(now);
}