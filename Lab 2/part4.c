#include <assert.h>

#include "part4.h"

long foo(long* p, long val)
{
	long ret;
	ret=*p;
	val=val+ret;
	p=&val;
	return ret;
}

long part4(long* array, int size)
{
	long ret;
	if(0<size){
		ret=0;
		array=array+ret*8;
		size=2;
		ret=foo(array, size);
		ret=ret+1;
	}
	else
		ret=0;
	
}
