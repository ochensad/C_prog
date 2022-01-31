#include "list_func.h"
#include "comand.h"

int main(void)
{
    int error_code = OK;
    int comand = -1;

    error_code = parse_comand(&comand);
    if (error_code)
        return error_code;
    error_code = ERROR_READING;
    if (comand == 1)
    {
        node_t *head = NULL;
        head = read_num();
        if (head == NULL)
        {
            free_list(head);
            return ERROR_READING;
        }
        print_list(head);
        free_list(head);
    }
    else if (comand == 2)
    {
        node_t *head_1 = NULL;
        node_t *head_2 = NULL;

        head_1 = read_num();
        if (head_1 == NULL)
        {
            free_list(head_1);
            return error_code;
        }
        head_2 = read_num();
        if (head_2 == NULL)
        {
            free_list(head_1);
            free_list(head_2);
            return error_code;
        }
        node_t *res = NULL;
        error_code = multiplication(&head_1, &head_2, &res);
        if (error_code)
        {
            free_list(head_1);
            free_list(head_2);
            free_list(res);
            return error_code;
        }
        print_list(res);
        free_list(head_1);
        free_list(head_2);
        free_list(res);
    }
    else if (comand == 3)
    {
        node_t *head = NULL;
        head = read_num();
        if (head == NULL)
        {
            free_list(head);
            return error_code;
        }
        node_t *res = NULL;
        error_code = multiplication(&head, &head, &res);
        if (error_code)
        {
            free_list(head);
            free_list(res);
            return error_code;
        }
        print_list(res);
        free_list(head);
        free_list(res);
    }
    else if (comand == 4)
    {
        node_t *head_1 = NULL;
        node_t *head_2 = NULL;

        head_1 = read_num();
        if (head_1 == NULL)
        {
            free_list(head_1);
            return error_code;
        }
        head_2 = read_num();
        if (head_2 == NULL)
        {
            free_list(head_1);
            free_list(head_2);
            return error_code;
        }
        node_t *res = NULL;
        error_code = division(&head_1, &head_2, &res);
        if (error_code == ERROR_LIST)
        {
            printf("0 L");
            free_list(head_1);
            free_list(head_2);
            free_list(res);
            return OK;
        }
        if (error_code != OK && error_code != ERROR_DIV && error_code != ERROR_DIV_ZERO)
        {
            free_list(head_1);
            free_list(head_2);
            free_list(res);
            return error_code;
        }
        if (error_code == ERROR_DIV_ZERO)
        {
            free_list(head_1);
            free_list(head_2);
            free_list(res);
            return error_code;
        }
        else
            print_list(res);

        free_list(head_1);
        free_list(head_2);
        free_list(res);
    }
    return OK;
}