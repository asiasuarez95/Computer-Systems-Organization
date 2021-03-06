#include <stdio.h>
#include <assert.h>
#include "util.h"

/*
Bitwise operators can also aid you in creating masks.
*/

/* TODO: Make a function flip_bit that takes the inputs (n, number)
         and then returns the number with the nth bit flipped.
         (with the ones bit being the 0th bit)*/
int flip_bit(char n, int number)
{
    /* Hint: Use a bit shift in order to get your mask into place
             and then use the XOR operator in order to flip the desired bit. */
    int mask = 0x0001;
    mask = mask << n;

    number = mask ^ number;
    return number;
}

int main()
{
    assert(flip_bit(0, 0) == 1);
    assert(flip_bit(1, 0) == 2);
    assert(flip_bit(2, 0) == 4);
    assert(flip_bit(3, 0) == 8);
    assert(flip_bit(4, 0) == 16);

    part_completed(10);

    return 0;
}