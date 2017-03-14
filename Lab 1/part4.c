#include <stdio.h>
#include <assert.h>

// Extract the 8-bit exponent field of single precision
// floating point number f and return it as an unsigned byte
unsigned char get_exponent_field(float f)
{
    unsigned char exp;
    int* fptr = (int*) &f;
    int fval = *fptr;
    fval = fval >> 23;
    int temp = 0b011111111;
    fval = (fval & temp);
    exp = fval;
    return exp;
}

// Clear the most significant b bits of unsigned integer number
// and return the resulting value.
// As an example, suppose
//   unsigned int number = 0xffff0000;
//   int b = 15;
// then the correct return value is 65536
// if b = 30, then the return value is 0
// if b = 40, the return value should also be 0
unsigned int clear_msb(unsigned int number, int b)
{
    int bitsleft= (32-b)-1;
    int base = 2;
    int unsigned totalTemp=base;

    int i;
    for (i=1; i<bitsleft; i++)
    {
        totalTemp = totalTemp*base;
    }
    if(b==0)
        return number;
    else
    number = (number&totalTemp);
    return number;
}



// Given an array of bytes whose length is array_size (bytes), treat it as a bitmap (i.e. an array of bits),
// and return the bit value at index i (from the left) of the bitmap.
//
// As an example, suppose char array[3] = {0x00, 0x1f, 0x12}, the corresponding
// bitmap is 0x001f12, thus,
// the bit at index 0 is bitmap[0] = 0
// the bit at index 1 is bitmap[1] = 0
// ...
// the bit at index 11 is bitmap[11] = 1
// the bit at index 12 is bitmap[12] = 1
// ...
// the bit at index 16 is bitmap[16] = 0
// ...
unsigned char bit_at_index(unsigned char *array, int array_size, int i)
{
    // TODO: Your code here
    assert(0);
}
