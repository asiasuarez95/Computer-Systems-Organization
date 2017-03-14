#include "lab4.h"

int main()
{
    //run the shell until EOF (keyboard Ctrl+D) is detected
    while (userinput( ) != EOF)
    {
        process();
    }
    return 0;
}
/*Part 1: Bug 1: Only the first command works properly
In process.c, I noticed that int narg was never initialized to zero,
which I felt was neccesary, because it should be reset after each call to
process.c. On line 11, I simply initialized the first apperance of the vairiable
and that seemed to take care of the bug.
*/

/*Part 2: Bug 2: cd command does not behave as expected
For Bug 2, I felt like it should also be resolved in process.c. Basically, we want
the user to be able to change their current working directory by typing cd somefile,
cd, or cd .. .This means that the number of arguments supplied by the user must be greater
than zero so we place a conditional statement (line 42) such that the number of arguments
does not equal zero. We do't worry about the possibility of negative arguments, as that
is unrealistic. Then, we want to compare the first inputed string to "cd", and if that holds
true, we know that we must change the directory. If the second argument, arg[1] is equivalent
to NULL or "  ", we know that the user should be redirected to their HOME directory. This is
shown in lines 49-54. Next, we also need to warn the user if their argument does not match with
an avaliable directory. I noticed that if the directory does not exist, (line 58) the chdir(arg[1])
will return a negative, so I formulated a conditional statement based on that. If the directory
does not exist, chdir(arg[1]) will return a negative number which will prompt the error message.
*/

/*Part 3: Bug 3: exit command does not terminate the shell
Again, I felt this was best handled in process.c. I restructured my code in part 2, to be
reliant on wether or not the first argument, arg[0] == "exit". If not, then it will check if
arg[0] =="cd". If the string compare between arg[0] and "exit" returned true, the program knows
that the user wants to terminate the program, thus exit(1). This portion of code is written on
lines 45 and 46.
*/

/*Part 4: Bug 4: Pressing Ctrl+C should not kill the shell
This part was a bit challenging for me. After a bit of research I found that it is necessary
to use a signal handler to catch Ctrl-C. Basically, I created a function, void sigint_handler(int sig),
that will ignore Ctrl-C, and also reinstall it. Still a bit uncertain about how this works
under the hood, but it passes the infinate while loop test case. You can find this adjustment to
the code on lines 81-85 (function) and its implementation on line 38 in proccess.c.
*/

/*Part 5: Bug 5: Background processes are not reaped
This too, I found a bit challeneging till I realised that I need to implement another signal
handler and also a function that manages to check over all children in the program.
By using waitpid, from what I understood from http://www.gnu.org/software/libc/manual/html_node/Process-Completion.html ,
-1 represents if the program should wait for the child processes, NULL means that we do not require a specific status,
WNOHANG which indicates that the parent process should not wait. Waitpid then reaps the child.
The function is on lines 43-45 and it implementation is on line 26.
*/

/*For my own benefit I just created a Folder called Test, with an empty file to test with the cd call.
Please ignore. */