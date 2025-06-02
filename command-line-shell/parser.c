#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

void parseInput(char *input, char **args)
{

    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL && i < 63)
    {

        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    for (int j = 0; args[j] != NULL; j++)
    {
        printf("arg[%d]: %s\n", j, args[j]);
    }
}
