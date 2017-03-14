#include <stdio.h>
#include <assert.h>
#include "util.h"

/*
 Write a function bit_wisdom that takes an integer n and..
    1. Turns off all of the bits except for the last 4 (1 2 4 8's bit)
    2. Flips the last two bits (1 and 2's)
    3. And turns on the second to last 2 bits. (4 and 8's. if its already on leave it on)
*/

int bit_wisdom(int n)
{
    //part 1, turn off all the bits except for the last 4
    int mask1 = 0b00001111;
    n = n & mask1;
    //part 2, flip the last two.
    int mask2 = 0b00000011;
    n = n ^ mask2;
    //part 3, turn on the second to last 2 bits.
    int mask3 = 0b00001100;
    n = n | mask3;
    return n;
}


int main()
{
    assert(bit_wisdom(0b11111111) == 0b00001100);
    assert(bit_wisdom(0b00000000) == 0b00001111);
    assert(bit_wisdom(0b10101010) == 0b00001101);
    assert(bit_wisdom(0b01010101) == 0b00001110);

    part_completed(11);

    return 0;
}