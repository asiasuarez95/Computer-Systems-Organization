#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int** load_file(FILE* file);
void printArray(int rows, int columns, int** matrix);
void freeArray(int rows, int** matrix);
void print1dArray(int rows, int* matrix);

int main()
{
    int i = 0;
    int j = 0;
    int **file_matrix;
    int *RowMaxMatrix;
    int *ColSumArray;

    FILE *file;
    file = fopen("twenty-five-ints.txt", "r");
    if(file==NULL)
    {
        printf("File could not be open. \n");
    }
    file_matrix = load_file(file);
    fclose(file);
    printArray(ROWS,COLS,file_matrix);

    RowMaxMatrix = row_max(file_matrix);
    printf("The row max is: \n");
    print1dArray(ROWS, RowMaxMatrix);

    ColSumArray = sum_cols(file_matrix);
    printf("\n The column sum is: \n");
    print1dArray(COLS, ColSumArray);

    free(ColSumArray);
    free(RowMaxMatrix);
    freeArray(ROWS, file_matrix);

    return 0;
}

int** load_file(FILE* file)
{
    int i, j;
    int count=0;

    int** matrix;
    matrix = (int**) malloc(ROWS*sizeof(int*));
    for (i=0; i<ROWS; i++)
    {
        matrix[i]=(int*) malloc(COLS*sizeof(int));
    }

    for(i = 0; i< ROWS; i++)
    {
        for(j = 0; j<COLS; j++)
        {
            fscanf(file, "%d\t", &matrix[i][j]);
        }
    }

    return matrix;
}

void printArray(int rows, int columns, int** matrix)
{
    int x,y;
    for(x=0; x<rows; x++)
    {
        for(y=0; y<columns; y++)
        {
            printf("%6i", matrix[x][y]);

        }
        printf("\n");
    }

    printf("\n");
}

void freeArray(int rows, int** matrix)
{
    int x;
    for(x=0; x<ROWS; x++)
    {
        free(matrix[x]);
    }
    free(matrix);
}

void print1dArray(int rows, int* matrix)
{
    int x,y;
    for(x=0; x<rows; x++)
    {
        printf("%6i", matrix[x]);
    }

    printf("\n");
}




