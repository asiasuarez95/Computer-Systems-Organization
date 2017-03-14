#include "matrix.h"
#include <stdlib.h>

int* row_max(int** array)
{
    int i,j;
    int rMax;
    int* rowMaxMatrix = (int*) malloc(ROWS*sizeof(int));
    for(i=0; i<ROWS; i++)
    {
        rMax= 0;
        for(j=0; j< COLS; j++)
        {
            if(rMax < array[i][j])
            {
                rMax = array[i][j];
            }
        }
        rowMaxMatrix[i] =rMax;
    }
    return rowMaxMatrix;
}


int* sum_cols(int** array)
{
    int i,j;
    int* colSumMatrix= (int*) malloc(COLS*sizeof(int));
    int sum;
    for(i=0; i< ROWS; i++)
    {
        sum=0;
        for(j=0; j<COLS; j++)
        {
            sum += array[j][i];
        }
        colSumMatrix[i]=sum;
    }
    return colSumMatrix;
}


