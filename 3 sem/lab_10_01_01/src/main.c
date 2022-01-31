#include "list_func.h"
#include "file_func.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int error_code;

    if (argc != 3)
        return ERROR_ARGV;
    
    char *f_in = argv[1];
    char *f_out = argv[2];

    set_t arr;

    FILE *f;
    f = fopen(f_in, "r");

    if (f == NULL)
        return ERROR_OPENING_FILE;

    if ((error_code = read_file(&arr, f)) != OK)
        return error_code;
    fclose(f);

    node_t *head = NULL;

    if ((head = get_list(&arr)) == NULL)
        return error_code;
    
    void *max = NULL;
    void *min = NULL;

    if ((error_code = list_task(&head, &min, &max)) != OK)
    {
        free_list(head);
        free(arr.arr);
        return error_code;
    }

    FILE *f_2;
    f_2 = fopen(f_out, "w");

    if (f_2 == NULL)
        return ERROR_OPENING_FILE;
    
    if (max == NULL && min != NULL)
        fprintf(f, "%d %d\n", *(int*) min, *(int*) min);
    else if (max != NULL && min != NULL)
        fprintf(f, "%d %d\n", *(int*) min, *(int*) max);

    print_list(head, f_2);

    fclose(f_2);
    free_list(head);
    free(arr.arr);

    return OK;
}