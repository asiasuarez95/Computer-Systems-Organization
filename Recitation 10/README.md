Recitation 10: Linking
=========

### Basic Linker knowledge

The `list.c` file in this directory implements a simple linked list. Compile this file into an object file and don't forget to include `-std=gnu99` flag. Explain the errors produced. Fix them to produce the object file `list.o`. The compile command is as follows:

```
	gcc -c -o list.o list.c -std=gnu99
```

Compile the `main.c` file included in this directory (also with the `-std=gnu99` flag) into an object file. Explain the errors produced. Fix them to produce the object file `main.o`:

```
	gcc -c -o main.o main.c -std-gnu99
```

Then, link the two object files into an executable (using `gcc`) to create the binary executable `linkedlist` (that you can run by typing `./linkedlist`).

Among the collection of names in `list.c` (as shown below), which are linker symbols and which are not? Which linker symbols are defined in `list.c` and which ones are not?
* `head`
* `n_inserts`
* `n_deletes`
* `insert`
* `prev`
* `curr`
* `malloc`
* `delete`
* `free`
* `find`

After you've answered the above question using sheer brainpower, let's find out the actual answer using the UNIX tool called `nm`. Run `nm list.o`. Read the man pages of `nm` (type `man nm`). And explain the nm output.  What are the symbols defined? What are the ones undefined? Then, run `nm main.o` and explain its output as well.

Lastly, run `nm ./linkedlist`. Which previously undefined symbols have now become defined? What are the remaining undefined symbols? What do these remaining undefined symbols correspond to?

### Linker and Shared library

We can examine the shared library (as in, the library that you included with `#include <stdlib.h>`) to be loaded with `./linkedlist` using the UNIX tool `ldd` (do `man ldd`). Type `ldd ./linkedlist` and find out the pathname of the shared library file that correspond to C standard library.

Now, let's examine the symbols defined in the C library to see if the remaining undefined symbols of  `./linkedlist` can indeed be found there. Type `nm -D <filename>` to list dynamic symbols. Did you find what you are looking for?

### Programming errors in the linking process

Now let's turn our attention to the actual output of `./linkedlist`. The program inserts 100 linked list nodes and then deletes half of them. Explain why the output statistics are so out of whack. Fix the errors.

Put all your explanations into a file name 'answers.txt' and push it to your repository.