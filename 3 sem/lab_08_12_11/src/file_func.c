#include "file_func.h"
#include <string.h>


int parse_argv(int argc, char **argv, int *action, char *file_name_1, char *file_name_2, char *file_res_name)
{
    if (argc == 4)
    {
        if (strcmp(argv[1], "o") == 0)
        {
            strncpy(file_name_1, argv[2], NAME_LEN);
            strncpy(file_res_name, argv[3], NAME_LEN);
            *action = 3;
        }
        else
            return ERROR_ACT_NUM;
    }
    else if (argc == 5)
    {
        if (strcmp(argv[1], "a") == 0)
        {
            strncpy(file_name_1, argv[2], NAME_LEN);
            strncpy(file_name_2, argv[3], NAME_LEN);
            strncpy(file_res_name, argv[4], NAME_LEN);
            *action = 1;
        }
        else if (strcmp(argv[1], "m") == 0)
        {
            strncpy(file_name_1, argv[2], NAME_LEN);
            strncpy(file_name_2, argv[3], NAME_LEN);
            strncpy(file_res_name, argv[4], NAME_LEN);
            *action = 2;
        }
        else
            return ERROR_ACT_NUM;
    }
    else
        return ERROR_ARGV;
    return OK;
}