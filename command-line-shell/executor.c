#include <stdlib.h>
#include <unistd.h> // fork, execvp
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "executor.h"

void runCommand(char **args)
{
    struct stat st;
    if (args[0] == NULL)
    {
        return; // empty command, do nothing
    }
    else if (strcmp(args[0], "cd") == 0)
    {

        if (stat(args[1], &st) == 0 && S_ISDIR(st.st_mode))
        {
            chdir(args[1]);
            return;
        }
        else
        {
            perror("cd failed");
            return;
        }
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        execvp(args[0], args);
        perror("execvp failed");
        exit(1); // only if exec fails
    }
    else if (pid > 0)
    {
        // Parent process
        wait(NULL); // Wait for child to finish
    }
    else
    {
        // Fork failed
        perror("fork failed");
    }
}
