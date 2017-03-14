# Computer Systems Organization : Homework 01
---------------------------------------------

Write a program that transposes randomly generated NxM matrices.

A matrix is is a rectangular 2d array of numbers arranged in rows and columns. Like so..

<pre>
10    6    -7     9
0    -2     4    -10
10    1     2    -3
</pre>

To transpose a matrix is to swap the values in the columns and rows. The above matrix transposed would be like so...

<pre>
10    0     10
6    -2     1
-7     4     2
9    -10   -3
</pre>

**Note:
If you have questions, post them to Piazza.

# Step 1

In main.c, generate N and M for the matrix (N and M should both be <= 10). You can use the rand() function demonstrated in main.c for you.

    Then create an array of NxM dimensions. Next assign each position of the matrix with a random value again using rand().

        Next, print the matrix to the console. You should create a print_matrix function prototype and definition in main.c itself. It should use *pointer notation* for the array parameter.

# Step 2

        Define the transpose function in transpose.c, put the declaration transpose.h. It should use *subscript notation* for the array parameter.

            Look at the lecture code for guidance on how to 'wire' a program consisting of multiple files together using the correct includes.

# Step 3

                Make the necessary modification to utilize the transpose function in main.c. Then transpose the array from step 1 and print the transposed array using the print_matrix function.

# Step 4

                Run astyle on your program.

Then execute the following series of commands from the directory that you checked out the repository to:
                <br/>
                ```git commit -am "Submitting homework 01"   ```<br/>
                ```git push origin master   ```<br/>

