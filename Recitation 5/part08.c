#include <stdio.h>
#include <assert.h>
#include "util.h"

/*
Using the >> and << bitwise operators can aid us in trying
to extract a particular bit in a bit vector.
*/

int main()
{
    /*
    TODO: Use a bit shift and a mask in order to get bit
    value of the 8's bit in 'a'.

    Hint: Use a right shift to get 'a' into the desired position
          and then bitwise AND it with your 'mask' to get the result.
    */

    int a = 0x10111;
    a = a<< 1;
    /* Initialize 'mask' and 'bit' with the right values */
    int mask = 0x1000;
    int bit = a & mask;

    assert(bit == 0b0);

    part_completed(8);

    return 0;
}