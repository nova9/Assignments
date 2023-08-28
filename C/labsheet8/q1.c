#include <stdio.h>

typedef struct Customer {
    char *name;
    int account_number;
    int balance;
} Customer;

void print_less_than_200(Customer *customers, int length) {
    for (int i = 0; i < length; i++) {
        if (customers[i].balance < 200) {
            printf("%s\n", customers[i].name);
        }
    }
}

void increment(Customer *customers, int length) {
    for (int i = 0; i < length; i++) {
        if (customers[i].balance > 1000) {
            customers[i].balance += 100;
            printf("%s, new balance = %d\n", customers[i].name, customers[i].balance);
        }
    }
}

int main() {
    Customer customers[] = {
            {"Thathsara", 232323, 7980},
            {"Madusha", 8085643, 56},
            {"Kavindu", 83489989, 59},
            {"Hirusha", 8234999, 45},
            {"Saranath", 823489, 23},
            {"Sudhara", 823489, 5344},
    };

    int customers_length = sizeof(customers) / sizeof(Customer);


    print_less_than_200(customers, customers_length);

    increment(customers, customers_length);
}