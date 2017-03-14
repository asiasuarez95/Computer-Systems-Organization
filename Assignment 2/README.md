# Computer Systems Organization : Homework 02

Write a program that loads file contents into a two-dimensional array on the heap, then prints some information about the contents of the 2d array using functions defined in a `matrix` library.

## Step 1

### In main.c

* Define two macros ROWS and COLS that both have the value 5, these are your array dimensions.
* Declare a function prototype `int** load_file(FILE* file);
` at the top of the file.
* Define the `load_file(..)` function at the bottom of the file. That function should load the 25 integers in the file into a ROWSxCOLS two-dimensional array allocated on the heap. (You can use calloc or malloc, up to you.)
* In `main()`...
* Declare and initialize a FILE struct to open the twenty-five-ints.txt text file.
        * Call the `load_file` function with the initialized FILE as the argument.
        * Store the double pointer return value in a value into a local variable called `matrix`.

## Step 2

### In matrix.h

                                          * Declare two functions
                                  * `int* row_max(int** array);
`
* `int* sum_cols(int** array);
`

### In matrix.c

* Define `row_max(..)` to returns an array of ints such that the value at index i is the largest element of the i'th row in the matrix passed as a parameter. For the below matrix the return value would be `[10, 4, 12]`.
* Define `col_sum(..)` to return an array of ints such that the value at index i is the sum of all element of the i'th column in the matrix passed as a parameter. For the below matrix the return value would be `[20, 5, 9]`.
        * What memory region should the return arrays be allocated to?

                ```
                10    6    -7
                0    -2     4
                10    1     12
                ```

## Step 3

### In main.c

                * Pass `matrix` to each of the functions you created in step 2.
                * Print the results to standard out.
                * Clean up after yourself by freeing memory and closing resources.

## Step 4

                * Run astyle on your program.
                * Execute the following series of commands from the directory that you checked out the repository to: <br/>
                ```git commit -am "Submitting homework 02"   ```<br/>
                ```git push origin master   ```<br/>

## Tip

                The [matrix can be allocated](http://stackoverflow.com/questions/2565039/how-are-multi-dimensional-arrays-formatted-in-memory) as a double pointer like so...
                        ```
                        int i;
                        int** array = (int**) malloc(ROWS * sizeof(int*));
                        for (i = 0; i < ROWS; ++i)
{
array[i] = (int*) malloc(COLS * sizeof(int));
}
```


