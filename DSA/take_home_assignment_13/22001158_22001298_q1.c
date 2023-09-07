#include <stdio.h>

// Define Student structure
typedef struct Student {
    int id;
    char name[50];
    float mathMarks;
    float physicsMarks;
    float chemistryMarks;
} Student;

// Define enums for sort criteria and sort order
enum SortCriteria {
    ID,
    MATH,
    PHY,
    CHEM
};
enum SortOrder {
    ASC,
    DESC
};

// Function to print the array of students
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

// Function to sort an array of students
void selectionSortStudent(Student *student, int length, enum SortCriteria sortCriteria, enum SortOrder sortOrder) {
    // Switch based on sort criteria
    switch (sortCriteria) {
        case ID:
            // Selection sort based on ID
            for (int i = 0; i < length; i++) {
                int selected = student[i].id;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    // Switch based on sort order
                    switch (sortOrder) {
                        case ASC:
                            // Ascending order
                            if (selected > student[j].id) {
                                selected = student[j].id;
                                pos = j;
                            }
                            break;
                        case DESC:
                            // Descending order
                            if (selected < student[j].id) {
                                selected = student[j].id;
                                pos = j;
                            }
                            break;
                    }
                }
                // Swap students
                Student temp = student[i];
                student[i] = student[pos];
                student[pos] = temp;
            }
            break;
        case MATH:
            for (int i = 0; i < length; i++) {
                float selected = student[i].mathMarks;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > student[j].mathMarks) {
                                selected = student[j].mathMarks;
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < student[j].mathMarks) {
                                selected = student[j].mathMarks;
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = student[i];
                student[i] = student[pos];
                student[pos] = temp;
            }
            break;
        case PHY:
            for (int i = 0; i < length; i++) {
                float selected = student[i].physicsMarks;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > student[j].physicsMarks) {
                                selected = student[j].physicsMarks;
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < student[j].physicsMarks) {
                                selected = student[j].physicsMarks;
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = student[i];
                student[i] = student[pos];
                student[pos] = temp;
            }
            break;
        case CHEM:
            for (int i = 0; i < length; i++) {
                float selected = student[i].chemistryMarks;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > student[j].chemistryMarks) {
                                selected = student[j].chemistryMarks;
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < student[j].chemistryMarks) {
                                selected = student[j].chemistryMarks;
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = student[i];
                student[i] = student[pos];
                student[pos] = temp;
            }
            break;
        default:
            // Print error message for unknown sort criteria
            printf("Unknown Criteria\n");
    }
}

int main() {
    // Define and initialize array of students
    Student students[] = {
            {2,  "Ravindu", 45, 67, 98},
            {1,  "Saman",   45, 76, 89},
            {32, "Madusha", 85, 27, 68},
            {4,  "Daham",   85, 97, 48},
    };

    // Calculate number of students
    int length = sizeof(students) / sizeof(Student);

    // Sort and print students
    selectionSortStudent(students, length, ID, ASC);
    selectionSortStudent(students, length, MATH, DESC);

    printStudentArray(students, length);
}