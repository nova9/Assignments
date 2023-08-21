#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int rowSize;
    int columnSize;
    int *matrix;
} Matrix;

Matrix create_matrix(int rowSize, int columnSize){
    Matrix matrix = {
            rowSize,
            columnSize,
            calloc(rowSize * columnSize, sizeof(int *))
    };
    return matrix;
}

Matrix init_matrix(Matrix matrix, const int *values){
    for (int i = 0; i < matrix.rowSize * matrix.columnSize; i++) {
        matrix.matrix[i] = values[i];
    }
    return matrix;
}

void print_matrix(Matrix *m){
    for(int i = 0; i < m->rowSize; i++){
        for(int j = 0; j < m->columnSize; j++){
            printf("%d  ", *(m->matrix + i * m->rowSize + j));
        }
        printf("\n");
    }
}

Matrix addition(Matrix m1, Matrix m2) {
    Matrix result = create_matrix(m1.rowSize, m1.columnSize);

    for (int i = 0; i < m1.rowSize * m1.columnSize; i++) {
        result.matrix[i] = m1.matrix[i] + m2.matrix[i];
    }
    return result;
}

Matrix subtraction(Matrix m1, Matrix m2) {
    Matrix result = create_matrix(m1.rowSize, m1.columnSize);

    for (int i = 0; i < m1.rowSize * m1.columnSize; i++) {
        result.matrix[i] = m1.matrix[i] - m2.matrix[i];
    }
    return result;
}

Matrix multiplication(Matrix m1, Matrix m2) {
    Matrix result = create_matrix(m1.rowSize, m2.columnSize);

    for (int i = 0; i < m1.rowSize; i++) {
        for (int j = 0; j < m2.columnSize; j++) {
            int sum = 0;
            for (int k = 0; k < m1.columnSize; k++) {
                sum += m1.matrix[m1.columnSize * i + k] * m2.matrix[m2.rowSize * k + j];
            }
            result.matrix[m1.rowSize * i + j] = sum;
        }
    }
    return result;
}

int main() {
	int matrix1_data[] = {
            3, 5, 7,
            1, 6, 5,
            4, 9, 8
	};
    Matrix m1 = init_matrix(
            create_matrix(3, 3),
            matrix1_data
            );

    int matrix2_data[] = {
            6, 0, 2,
            4, 7, 1,
            7, 2, 1
    };
    Matrix m2 = init_matrix(create_matrix(3, 3), matrix2_data);

    printf("Addition\n");
    Matrix add = addition(m1, m2);
    print_matrix(&add);
    printf("\n");

    printf("Subtraction\n");
    Matrix sub = subtraction(m1, m2);
    print_matrix(&sub);
    printf("\n");

    printf("Multiplication\n");
    Matrix mul = multiplication(m1, m2);
    print_matrix(&mul);
    printf("\n");
}
