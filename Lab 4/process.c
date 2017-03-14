#include "lab4.h"

/* Shell input line */
int process(void)
{
    char *arg[MAXARG + 1];  /* pointer array for runcommand */
    int toktype;            /* type of token in command */

    /* narg should be initialized to zero because it should be reset
    after each call to process*/
    int narg = 0;              /* number of arguments so far */

    int type;               /* type = FOREGROUND or BACKGROUND */

    while (1)
    {
        /* Take action according to token type */
        switch(toktype = gettok(&arg[narg]))
        {
        case ARG:
            if(narg < MAXARG)
            {
                narg++;
            }
            break;

        case EOL:

        case SEMICOLON:

        case AMPERSAND:
            if(toktype == AMPERSAND)
            {
                type = BACKGROUND;
            }
            else
            {
                type = FOREGROUND;
                //part 4
                signal(SIGINT,sigint_handler);
            }



            if(narg != 0)
            {
                //Resolve Bug 3
                if(strcmp(arg[0], "exit")==0)
                {
                    exit(1);
                }
                //Resolve Bug 2
                else if (strcmp(arg[0], "cd")==0)
                {
                    if (narg==1)
                    {
                        if (getenv(arg[1])==NULL)
                        {
                            chdir(getenv("HOME"));
                            printf("New directory is %s\n",getenv("HOME"));
                        }
                    }
                    else if(chdir(arg[1])<0)
                    {
                        printf("%s is not a directory. Try again.\n",arg[1]);
                        // printf("%d .\n",chdir(arg[1]));
                    }
                }

                else
                {
                    arg[narg] = 0;
                    runcommand(arg,type);
                }
            }

            if(toktype == EOL)
            {
                return;
            }

            narg = 0;

            break;
        }
    }
}

void sigint_handler(int sig)
{

    signal(sig,SIG_IGN);//ignore it
    signal(SIGINT,sigint_handler);//reinstall sigint_handler
}