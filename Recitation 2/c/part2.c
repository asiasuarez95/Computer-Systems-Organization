#include <stdio.h>

void swap(int *p1, int *p2);

int main(int argc, char **argv)
{
    int val0 = 1;
    int val1 = 2;

    swap(&val0, &val1);

    if(1 != val1)
    {
        printf("first value not properly swapped\n");
    }
    else if(2 != val0)
    {
        printf("second value not properly swapped\n");
    }
    else
    {
        printf("part2: OK\n");
    }
    return 0;
}

// Swap the values of the integer variables pointed to by p1 and
// p2.  After the function returns, the variable pointed to by p1
// should have the value once pointed to by p2, and vice-versa.
void swap(int *p1, int *p2)
{
    // TODO: Your code here.
}
