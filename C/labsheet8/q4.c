#include <stdio.h>

typedef struct Employee {
    char *name;
    int salary;
    int hours_of_work_per_day;
} Employee;

void increase(Employee *employees, int length) {
    for (int i = 0; i < length; i++) {
        if (employees[i].hours_of_work_per_day >= 12) {
            employees[i].salary += 1500;
        } else if (employees[i].hours_of_work_per_day >= 8) {
            employees[i].salary += 1000;
        } else if (employees[i].hours_of_work_per_day >= 4) {
            employees[i].salary += 500;
        }
    }
}

void print_employees(Employee *employees, int length) {
    for (int i = 0; i < length; i++) {
        printf("%s(salary = %d)\n", employees[i].name, employees[i].salary);
    }
}

int main() {
    Employee employees[] = {
            {"Employee1", 200000, 8},
            {"Employee2", 250000, 4},
            {"Employee3", 20000, 6},
            {"Employee4", 690000, 7},
            {"Employee5", 620000, 9},
            {"Employee6", 50000, 9},
            {"Employee7", 670000, 10},
            {"Employee8", 230000, 4},
            {"Employee9", 40000, 1},
            {"Employee10", 20000, 5},
    };
    int length = sizeof(employees) / sizeof(Employee);

    increase(employees, length);
    print_employees(employees, length);
}