#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

int main()
{
    char *userInput = malloc(sizeof(char) * 1024);
    char *argv[64];

    printf("cwe-shell> ");
    fgets(userInput, 1024, stdin);
    userInput[strcspn(userInput, "\n")] = 0;

    while (strcmp(userInput, "exit") != 0)
    {

        parseInput(userInput, argv);
        runCommand(argv);
        printf("cwe-shell> ");
        fgets(userInput, 1024, stdin);
        userInput[strcspn(userInput, "\n")] = 0;
    }
    free(userInput);
    userInput = NULL;
    return 0;
}
