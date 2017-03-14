#include <assert.h>

#include <stdlib.h>

#include "part5.h"

long bar(long * a, int size)
{
	long var1=0;
	long var2;
	long var3=1;
	long ret=0;
	if (size>var1)
	{
		 var2=var1;
		 var2=(long) a+var2*8;
		 ret=var2+ret;
		 var3=var3*var2;
		 var1=var1+1;
	}
	else
		ret=ret+var3;

	return ret;

    // // TODO: Your code here.
    // assert(0);
    // return 0;
}

long part5(int size)
{
	long var1;
	long ret;
	var1= size;
	ret=size;
	ret=22+ret*8;
	ret=(ret&0xfffffffffffffff);
    // // TODO: Your code here.
    // assert(0);
    // return 0;
}
