#include "comand.h"
#include <stdlib.h>
#include <string.h>

int parse_comand(int *comand)
{
    char s[STR_MAX + 2];
    int ch;
    size_t len = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (len < STR_MAX)
            s[len++] = ch;
        else
            return ERROR_READING;
    if (len == 0)
        return ERROR_READING;
    s[len] = '\0';

    if (strcmp(s, "out") == 0)
        *comand = 1;
    else if (strcmp(s, "mul") == 0)
        *comand = 2;
    else if (strcmp(s, "sqr") == 0)
        *comand = 3;
    else if (strcmp(s, "div") == 0)
        *comand = 4;
    else
        return ERROR_ARGV;

    return OK;
}