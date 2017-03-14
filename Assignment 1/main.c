#include <stdio.h>
#include <stdlib.h>
#include "transpose.h"

void printArray(int rows, int columns, int matrix[rows][columns]);

int main()
{

    int seed = time(NULL);
    srand(seed);

    int rowSize = rand () % 10 + 1; //n
    int columnSize = rand () % 10 + 1; //m


    int matrix [rowSize][columnSize];
    int newMatrix[columnSize][rowSize];

    int i, j;

    for(i =0; i<rowSize; i++)
    {
        for(j=0; j<columnSize; j++)
        {
            matrix[i][j] = rand()%50;

        }

    }

    printf("The original array is: \n");
    printArray(rowSize, columnSize, matrix);


    printf("After transpose: \n");

    transpose(rowSize,columnSize,matrix,newMatrix);
    printArray(columnSize, rowSize, newMatrix);

    return 0;
}

void printArray(int rows, int columns, int array[rows][columns])
{
    int x,y;
    for(x=0; x<rows; x++)
    {
        for(y=0; y<columns; y++)
        {
            printf("%6i", array[x][y]);

        }
        printf("\n");
    }

    printf("\n");
}


