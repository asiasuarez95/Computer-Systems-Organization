#include "lab4.h"

// Execute a command with optional wait
int runcommand(char** cline, int where)
{
    pid_t pid;
    int status;

    switch(pid = fork())
    {
    case -1:
        perror(SHELL_NAME);
        return (-1);
    case 0:
        execvp(*cline,cline);
        //we should never get to this code, since execve does not return
        perror(*cline);
        exit(1);
    }

    // Code for parent
    // If background process print pid and exit program is running in the background
    if(where == BACKGROUND)
    {
        //part 5
        signal(SIGCHLD,control_Child);
        printf("[Process id %d]\n",pid);
        return 0;
    }

    // Wait until process pid exits
    if (waitpid(pid,&status,0) == -1)
    {
        return -1;
    }
    else
    {
        return status;
    }

}

void control_Child()
{
    while(waitpid(-1,NULL,WNOHANG)>0);
}
