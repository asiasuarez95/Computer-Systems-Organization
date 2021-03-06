/***********************************************/
/* Do not change anything below this line      */
/***********************************************/

#define SMALL   64
#define N       1024
#define DIM     512
#define DIM2    1024
#define LARGE   10000
#define LARGER  50000

char* part3();

char* part3_opt();

/***********************************************/
/* Do not change anything above this line      */
/***********************************************/

/* 
 * If you wish to use a different definition
 * of the following structure, provide a new
 * definition (do not remove the existing one).
 */

typedef struct { 
    char c1;
    double f1;
    int n1; 
    char c2;
    int n2;
    double f2; 
} data; 

//Reorder and organize the var so that when pt3_opt is run
//it calls struct vars that are close to eachother
//Improves spatial locality.
typedef struct { 
    char c1;
    char c2;
    int n1; 
    int n2;
    double f1;
    double f2; 
} dataN; 

