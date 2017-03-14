/* Definitions: */

void transpose( int rows2, int columns2, int matrix[rows2][columns2], int transMatrix[columns2][rows2])
{
    int a,b;
    for(a=0; a<rows2; a++)
    {
        for(b=0; b<columns2; b++)
        {
            transMatrix[b][a]= matrix[a][b];
        }
    }

}