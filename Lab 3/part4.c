#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "part4.h"

/*
 * Implement the C function called part4_opt. It should perform
 * the same task as the implemented part4 function. In the
 * comments for the function describe why your changes make the
 * function more cache friendly.
 * 
 * Note: your function needs to compute the entire matrix C, not only C[x]. 
 */

long part4(long* B, long* A, int x) {
    long* C = (long*) calloc(N, sizeof(long));
    if (!C) return 0; 
    
    int c, r; 
    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[r] = B[r * N + c] + A[c * N + r];
    
    long ret = C[x];
    free(C); 
    return ret;
}

long part4_opt(long* B, long* A, int x) {
    long* C = (long*) calloc(N, sizeof(long));
    if (!C) return 0; 
    //Create temp arrays to store values that can be easily accessed. 
    long* first = (long*) calloc(N, sizeof(long));
    long* second = (long*) calloc(N, sizeof(long));
//iterate first part of C[r]
    int c, r;
    for(c=0;c<N; c++){
        for(r=0;r<N;r++){
            first[r]=A[N*c+r];
        }
    }
    //iterate second part of C[r]
    for(r=0;r<N;r++){
        for(c=0;c<N;c++){
            second[r]=B[N*r+c];
        }
    }
    //add both array values at r to form C[r]
    for(r=0;r<N; r++){
        C[r]=first[r]+second[r];
    }
    //DO NOT modify the rest of this function 
    long ret = C[x];
    free(C); 
    return ret;
}
