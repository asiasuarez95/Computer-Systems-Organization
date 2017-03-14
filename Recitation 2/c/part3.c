#include <stdio.h>

int array_sum(int *arr, int n);

int main ()
{
    const int size = 10;
    int a[size];
    int i;
    for (i = 0; i < size; i++)
    {
        a[i] = i;
    }

    if(45 != array_sum (a, size))
    {
        printf("sum of all elements is incorrect\n");
    }
    else if(10 != array_sum (a, size / 2))
    {
        printf("sum of first half of elements is incorrect\n");
    }
    else if(35 != array_sum (a + 5, size / 2))
    {
        printf("sum of second half of elements is incorrect\n");
    }
    else
    {
        printf("part3: OK\n");
    }

    return 0;
}


// Return the sum of all elements in the given array up to the limit of "n".
//
// Note that before, we used pointers to reference single variables
// in memory, but now we are using them to refer to many elements.
// The "arr" pointer points to the first element in the array in memory.
// Because pointers themselves don't carry any length information
// (like array objects do in Java), we generally have to pass in a
// length parameter to functions which use pointers to reference
// arrays.
int array_sum(int *arr, int n)
{
    // TODO: Your code here.
    return 0;
}
