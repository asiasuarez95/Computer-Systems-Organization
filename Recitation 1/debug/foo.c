#include <stdio.h>

void foo()
{
    int sum = 0;
    int i = 1;
    while (i <= 10)
    {
        sum += i;
        i++;
        //Must incriment i to terminate for loop.
    }
    printf("foo: sum of 1...10 is %d\n", sum);
}