#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

// Helper function
char* short_to_binary(unsigned short x);

// If odd Return 1 for true or 0 for false.
int is_odd(int i)
{
    if(i & 1)
    {
        return 1;
    }
    else
        return 0;
}

// Determines the number of 1s
int count_bits(unsigned long l)
{

    l -= ((l >> 1) & 0x5555555555555555);
    l = (l & 0x3333333333333333) + ((l >> 2) & 0x3333333333333333);
    return (int)((((l + (l>>4)) & 0xF0F0F0F0F0F0F0F) * 0x101010101010101) >> 56);

}

// 'interleaves' their bits into a short.
unsigned short interleave_bits(unsigned char x, unsigned char y)
{
    unsigned short z = 0;
    int i;
    for ( i = 0; i < 16; i++)
    {
        z = z |(((y & (1 << i)) << i) | ((x & (1 << i)) << (i + 1)));
    }
    return z;
}

char* short_to_binary(unsigned short x)
{
    static char b[17];
    b[0] = '\0';

    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

