#include <assert.h>

#include "part3.h"

char part3(long x, int b)
{
    char value;
    char valueTwo;

    if (b<0){
    	value= 0;
    	return value;
    }
	else if(b>7){
		value =0; 
		return value;
	}
	else {
			valueTwo= b*8;
			x = x>>valueTwo;
			value=x; 
			return value;
		}
    

        return value;
//     assert(0);
//     return 0;
}