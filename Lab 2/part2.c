#include <assert.h>

#include "part2.h"

long part2(long x, long y)
{
    long valueOne;
    long valueTwo;

    valueOne= 48*y; //y+2Y=3y shift 4 so 3y* 2^4 =48
    valueTwo= 31+x; //0x1f=31

    if(x>0)
        valueTwo=x;

    valueTwo=valueTwo/32; //shift 2^5 so divide by 32
    valueOne=valueOne&valueTwo;

    return valueOne;

}
