// sparse_matrix.c
// Sparse Matrix representation using Triplet Format

#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void printSparseMatrix(Element sparse[], int nonZero) {
    printf("Sparse Matrix Representation (Triplet Format):\n");
    printf("Row\tCol\tValue\n");
    for(int i = 0; i < nonZero; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    // Original 5x5 matrix
    int matrix[5][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0},
        {1, 0, 0, 0, 9}
    };
    
    // Count non-zero elements
    int nonZeroCount = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(matrix[i][j] != 0) nonZeroCount++;
        }
    }
    
    // Create sparse representation
    Element sparse[nonZeroCount];
    int index = 0;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(matrix[i][j] != 0) {
                sparse[index].row = i;
                sparse[index].col = j;
                sparse[index].value = matrix[i][j];
                index++;
            }
        }
    }
    
    printSparseMatrix(sparse, nonZeroCount);
    return 0;
}