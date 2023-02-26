#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void matrixMult(int** m1, int** m2, int** res, int size);
void freeMatrix(int ** matrix, int size);
int** initMatrix(int size, int val);
void printMatrix(int** matrix, int size);

int main(void){    
    struct timeval tv;
    int temps = 0;
    long start = 0;
    long end = 0;

    // Init matrices
    int** matrix1;
    int** matrix2;
    int** matrixRes;

    // Matrix size
    int mSize = 0;

    FILE *file;
    file = fopen("c_times.csv", "w+");

    for(int i = 10; i <= 150; i = i + 2) {
        mSize = i;

        matrix1 = initMatrix(mSize, 1);
        matrix2 = initMatrix(mSize, 2);
        matrixRes = initMatrix(mSize, 0);

        // Get start time
        gettimeofday(&tv,NULL);
        start = 1000000 * tv.tv_sec + tv.tv_usec;

        matrixMult(matrix1, matrix2, matrixRes, mSize);

        // Get end time
        gettimeofday(&tv,NULL);
        end = 1000000 * tv.tv_sec + tv.tv_usec;

        // Compute spent time in micro-seconds
        temps = (int)(end - start);

        fprintf(file, "%d,%d\n", i, temps);

        printf("%d Temps : %f secondes\n", i, temps / 1000000.0);

        // Free memory
        freeMatrix(matrix1, mSize);
        freeMatrix(matrix2, mSize);
        freeMatrix(matrixRes, mSize);
    }

    fclose(file);
}

// Print matrix in the console
void printMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Init matrix with val
int** initMatrix(int size, int val)
{
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        matrix[i] = (int*)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = val;
        }
    }

    return matrix;
}

// Multiply m1 with m2 into res
void matrixMult(int** m1, int** m2, int** res, int size)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Free memory from a matrix
void freeMatrix(int ** matrix, int size)
{
    for(int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}