# Computer Systems Organization : Recitation 02

- [C Programming](#c-programming)
- [Basic UNIX](#basic-unix-usage)
- [Debugging](#debug)

## C Programming

In this recitation you will be writing some of your first C programs. These exercises
are ideally done induvidually, however, if you do not have a laptop, talk to the TA
and he may pair you with someone who does if you do not have a partner already.

### Exercises

* Complete all three programs in the 'c' directory of this repository. Do not touch the main methods, simply provide implementations for the function stubs provided.

* Commit and push your solutions to Github.
```  
  git commit -m "commit..." <filename>.c
  git push origin master
```

---

## Basic UNIX usage

Most of you are used to interacting with computers and smartphones by GUI and
the touch interface.  As a developer / programmer / advanced user, you
can do your job more efficiently by mastering the commandline interface.  In
UNIX, most of the interesting things you want to do can be accomplished by skillfully combining
various commands.  

Your lab virtual machine is a Linux box.  Your MacOS laptop is based on BSD
UNIX.  Most UNIX commands you learn apply to both, but there are
variations.

Please read this [ guide on using UNIX commands ](https://github.com/jlevy/the-art-of-command-line).
Below is a short list of the most basic commands you will typically use on a day to day basis:

* `ls`
* `cd` `pwd`
* `mkdir`
* `cp` `mv` `rm`
* `echo` `cat`
* `wc`
* `|` `>` `<`
* `grep`
* `tail` `head` 
* `find`
* `ctrl-c` `ctrl-z` `fg` `bg`
* `tar`
* `curl` `wget`
* `apt-get install` (This is a Linux-distribution specific command, and hence not available on Mac or other non-Ubuntu based distributions; for Mac, a similar package manager called Brew exists)
* `apt-cache search` (same as above)

Despite attending this recitation, many times you will have questions about "how do I do this?"
"is there a command for doing X?".  The answer to all of these questions can usually
be discovered by Googling.  Click on those Stackoverflow links.  It has many helpful answers.

---

### Exercises

* In the 'unix' directory in this repository make a subdirectory called 'backup'. Copy unix/foo.txt into it.

* Rename the file foo.txt to answers.txt using the command line. (You will put the answers to the next set of exercises into this file.)

* Using the command line only, download and extract the source code of Nginx, a web server. The code's URL is at here: http://nginx.org/download/nginx-1.9.2.tar.gz 

* Using the command line only, find out which C source file contains the `main` function for Nginx.

* Using the command line only, find out how many lines are inside the nginx.c file (hint: one solution requires you to run multiple commands separately).

* Commit and push answers.txt to Github:
```  
  git commit -m "commit..." <filename>.txt
  git push origin master
```
---

## Debug

The debugger for C/C++ is `gdb`, developed by GNU, again.  In order to use gdb, we need to compile the
source code using the `-g` flag to include appropriate debug information in the generated binary files.
An example, `gcc -c -g foo.c`.

My foo program is buggy, and does not even terminate!
To debug, type `gdb foo`.  The most basic gdb commands are: (I give their shortcut form)
- `r` (run the program)
- `<ctrl-c>` to stop the program inside gdb
- `bt` (print out the stack, i.e. where in the program's execution it is being stopped at)
- `l` (print lines from the relevant source file)
- `p <variable name>` (print out the content of the variable)
- `b` (set breakpoints, e.g. `b foo.c:7` stops the program when it is about to execute line 7 at foo.c
- `n` (continue execution to the next source line) `s` (continue until control reaches a different source file)
- `c` (continue execution)

### Exercises

* Use gdb to debug foo (it is supposed to calculate and print the sum from 1 to 10) (how can you interrupt foo while it is running?).
* When you discover the problem with the program via gdb, take a screen shot of the console.
* Add the screen shot to Github.
* Fix the program.
* Commit and push the debugged foo.c to Github.
```
  git commit "debugged" foo.c 
  git push origin master
```
