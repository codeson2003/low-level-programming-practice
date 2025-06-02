#include <stdlib.h>
#include <unistd.h> // fork, execvp
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "executor.h"

void runCommand(char **args)
{
    if (args[0] == NULL)
    {
        return; // empty command, do nothing
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
