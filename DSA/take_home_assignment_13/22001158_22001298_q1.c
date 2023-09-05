#include <stdio.h>

typedef struct Student {
    int id;
    char name[50];
    float mathMarks;
    float physicsMarks;
    float chemistryMarks;
} Student;

enum SortCriteria {
    ID,
    MATH,
    PHY,
    CHEM
};

void printStudentArray(Student *students, int length) {
    printf("-------------------------------------------------------------------------------------------\n");
    printf("ID\t\tName\t\tMath\t\tPhysics\t\tChemistry\tTotal Marks\n");
    printf("-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < length; i++) {
        float total = students[i].mathMarks + students[i].physicsMarks + students[i].chemistryMarks;
        printf("%d\t\t%s\t\t%.1f\t\t%.1f\t\t%.1f\t\t%.1f\n",
               students[i].id,
               students[i].name,
               students[i].mathMarks,
               students[i].physicsMarks,
               students[i].chemistryMarks,
               total
               );
    }
}

void selectionSortStudent(Student *student, int length) {
    for (int i = 0; i < length; i++) {
        int small = student[i].id;
        size_t pos = i;
        for (int j = i + 1; j < length; j++) {
            if (small > student[j].id) {
                small = student[j].id;
                pos = j;
            }
        }
        Student temp = student[i];
        student[i] = student[pos];
        student[pos] = temp;
    }
}

int main() {
    Student students[] = {
            {1, "Ravindu", 45, 67, 98},
            {2, "Saman", 54, 76, 89},
            {32, "Madusha", 85, 27, 68},
            {4, "Daham", 85, 97, 48},
    };

    int length = sizeof(students) / sizeof(Student);

    selectionSortStudent(students, length);
    printStudentArray(students, length);
}