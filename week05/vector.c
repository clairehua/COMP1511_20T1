#include <stdio.h>

#define SCALAR 4

// function prototype
void scalar_multiply(int rows, int columns, int matrix[rows][columns], int scalar);
void fill_array(int rows, int columns, int matrix[rows][columns], int number);

int main(void) {

    int rows = 5;
    int columns = 5;
    
    int matrix[rows][columns];

    fill_array(rows, columns, matrix, 1);
    scalar_multiply(rows, columns, matrix, 6);


    int i = 0;
    int j = 0;
    
    while (i < rows) {
        j = 0;
        while (j < columns) {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}

void scalar_multiply(int rows, int columns, int matrix[rows][columns], int scalar) {
    int i = 0;
    int j = 0;
    
    while (i < rows) {
        j = 0;
        while (j < columns) {
            matrix[i][j] = matrix[i][j] * scalar;
            j++;
        }
        i++;
    }

    return;
}


void fill_array(int rows, int columns, int matrix[rows][columns], int number) {
    int i = 0;
    int j = 0;
    
    while (i < rows) {
        j = 0;
        while (j < columns) {
            matrix[i][j] = number;
            j++;
        }
        i++;
    }

    return;
}
