#include <stdio.h>
#include <stdlib.h>

// Define Student structure
typedef struct Student {
    int id;
    char *name;
    float mathMarks;
    float physicsMarks;
    float chemistryMarks;
} Student;

// Define enums for sort criteria and sort order
enum SortCriteria {
    ID,
    MATH,
    PHY,
    CHEM,
    TOTAL
};
enum SortOrder {
    ASC,
    DESC
};

float get_total(Student student) {
    return student.chemistryMarks + student.physicsMarks + student.mathMarks;
}

// Function to print the array of students
void printStudentArray(Student *students, int length) {
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("ID\t\t%-20s\t\tMath\t\tPhysics\t\tChemistry\tTotal Marks\n", "Name");
    printf("------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < length; i++) {
        float total = students[i].mathMarks + students[i].physicsMarks + students[i].chemistryMarks;
        printf("%d\t\t%-20s\t\t%.1f\t\t%.1f\t\t%.1f\t\t%.1f\n",
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
void selectionSortStudent(Student *students, int length, enum SortCriteria sortCriteria, enum SortOrder sortOrder) {
    // Switch based on sort criteria
    switch (sortCriteria) {
        case ID:
            // Selection sort based on ID
            for (int i = 0; i < length; i++) {
                int selected = students[i].id;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    // Switch based on sort order
                    switch (sortOrder) {
                        case ASC:
                            // Ascending order
                            if (selected > students[j].id) {
                                selected = students[j].id;
                                pos = j;
                            }
                            break;
                        case DESC:
                            // Descending order
                            if (selected < students[j].id) {
                                selected = students[j].id;
                                pos = j;
                            }
                            break;
                    }
                }
                // Swap students
                Student temp = students[i];
                students[i] = students[pos];
                students[pos] = temp;
            }
            break;
        case MATH:
            for (int i = 0; i < length; i++) {
                float selected = students[i].mathMarks;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > students[j].mathMarks) {
                                selected = students[j].mathMarks;
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < students[j].mathMarks) {
                                selected = students[j].mathMarks;
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = students[i];
                students[i] = students[pos];
                students[pos] = temp;
            }
            break;
        case PHY:
            for (int i = 0; i < length; i++) {
                float selected = students[i].physicsMarks;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > students[j].physicsMarks) {
                                selected = students[j].physicsMarks;
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < students[j].physicsMarks) {
                                selected = students[j].physicsMarks;
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = students[i];
                students[i] = students[pos];
                students[pos] = temp;
            }
            break;
        case CHEM:
            for (int i = 0; i < length; i++) {
                float selected = students[i].chemistryMarks;
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > students[j].chemistryMarks) {
                                selected = students[j].chemistryMarks;
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < students[j].chemistryMarks) {
                                selected = students[j].chemistryMarks;
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = students[i];
                students[i] = students[pos];
                students[pos] = temp;
            }
            break;
        case TOTAL:
            for (int i = 0; i < length; i++) {
                float selected = get_total(students[i]);
                size_t pos = i;
                for (int j = i + 1; j < length; j++) {
                    switch (sortOrder) {
                        case ASC:
                            if (selected > get_total(students[j])) {
                                selected = get_total(students[j]);
                                pos = j;
                            }
                            break;
                        case DESC:
                            if (selected < get_total(students[j])) {
                                selected = get_total(students[j]);
                                pos = j;
                            }
                            break;
                    }
                }
                Student temp = students[i];
                students[i] = students[pos];
                students[pos] = temp;
            }
            break;
        default:
            // Print error message for unknown sort criteria
            printf("Unknown Criteria\n");
    }
}

void get_students(Student *students, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        printf("ID: ");
        int id;
        scanf("%d", &id);

        printf("Name: ");
        char *name = malloc(sizeof(char) * 50);
        scanf("%s", name);

        printf("Mathematics: ");
        float mathematics;
        scanf("%f", &mathematics);

        printf("Physics: ");
        float physics;
        scanf("%f", &physics);

        printf("Chemistry: ");
        float chemistry;
        scanf("%f", &chemistry);

        Student student = {id, name, mathematics, physics, chemistry};
        students[i] = student;
    }
}

int main() {
    printf("How many students? ");
    int number_of_students;
    scanf("%d", &number_of_students);

    Student students[number_of_students];

    get_students(students, number_of_students);

    // First students are sorted
    selectionSortStudent(students, number_of_students, ID, ASC);
    selectionSortStudent(students, number_of_students, TOTAL, DESC);

    printStudentArray(students, number_of_students);
}