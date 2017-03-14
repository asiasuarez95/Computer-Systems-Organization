# Computer Systems Organization : Recitation 04

- [Make](#make)
- [Linked List](#linked-list)

## Make

So far you have used the C compiler, command `gcc`, to compile your C programs.

Typically, we do not directly type `gcc` to compile programs. There are several reasons for why not:
- The gcc command for large software is very long
- We need to compile many source files individually and combine them into a single execuable later.
- We need to obey dependencies during compilation. e.g. First compile x, then compile Y (if Y uses X).
- We only want to compile those source files that have changed.  

To address all above problems, we use a classic tool called `make`, developed by GNU. To use `make`, you write
a Makefile.  The meat of a Makefile consists of a bunch of rules.  Here's what a rule looks like
```
target: dependency1 dependency2
         commands
```

In the make directory, there is a Makefile that compiles the source files therein into and executable called `foo`:  

```
foo: foo.o main.o
    gcc -o foo foo.o main.o
main.o: main.c
    gcc -c main.c
foo.o: foo.c
    gcc -c foo.c
clean:
    rm -f foo.o foo
```
**Question:** type `make`, what is the order of the commands being run? why?

To make writing such rules more succinct, you use variables and do [pattern matching]([https://www.gnu.org/software/make/manual/html_node/Pattern-Match.html)in Makefile.
- Define variables as `FILES:=file1 file2`, use it later as `$FILES`

There are several important [automatic variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html).
- `$@` (target name)
- `$^` (name of all pre-requisites, i.e. dependencies)
- Pattern-matching using `%` and `*`. As an example:
```
  %.b: %.a
       cp  $*.a $*.b
```
  Above rule copies any file with suffix `.a` into another file with the same name except having suffix `.b`

### Exercises

* Rewrite the given Makefile using pattern matching and variables. Make it as clean and re-usable as possible. 
* Commit and push these changes to your Github repository.

## Linked List

In the linked_list directory there is a partial implementation of a linked list.

### Exercises

* Create a file called "double_trouble.txt", inside it, answer why the `add_head` and `remove_head` functions take as arguments `node**` as opposed to simply a `node*`. What would happen if the arguments were not double pointers? Feel free to experiement with the code to understand. (Make sure to `git add` that file!)
* There is serious bug related to dynamic memory allocation with the list implementation so far. Find it and fix it.
* Create a Makefile for the linked list. (Make sure to `git add` that file!)
* Commit and push these changes to your Github repository.

##### Bonus

* Implement `insert_at` and `remove_at` as commented in the header file. Update main.c to show their use. (Completing this in addition to everything else gets you an extra point.)

