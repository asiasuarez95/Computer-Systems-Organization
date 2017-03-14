#include <assert.h>

#include "part1.h"

long part1(long x, long y)
{
    long result; /*%rax return value*/
    if (x<=y)
        result=y;
    else
        result=x;
    return result;
}
