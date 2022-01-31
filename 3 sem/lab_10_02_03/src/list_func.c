#include "struct.h"
#include "list_func.h"
#include <stdlib.h>
#include <math.h>

void print_list(node_t *head)
{
    if (head == NULL)
        return;
    node_t *cur = head;

    for (; cur; cur = cur->next)
    {
        if (cur->next == NULL)
            printf("%d L", cur->exp);
        else
            printf("%d ", cur->exp);
    }
}

void free_list(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}

int get_num_arr(int n, num_t *arr)
{
    int d = 2;
    int *tmp;
    arr->arr = NULL;
    arr->size = 0;
    while (d * d <= n)
    {
        if (n % d == 0)
        {
            tmp = realloc(arr->arr, (arr->size + 1) * sizeof(int));
            if (tmp == NULL)
            {
                free(arr->arr);
                return ERROR_MEMORY;
            }
            arr->arr = tmp;

            arr->arr[arr->size] = d;
            arr->size++;
            n /= d;
        }
        else
            d++;
    }
    if (n > 1)
    {
        tmp = realloc(arr->arr, (arr->size + 1) * sizeof(int));
        if (tmp == NULL)
        {
            free(arr->arr);
            return ERROR_MEMORY;
        }
        arr->arr = tmp;
        arr->arr[arr->size] = n;
        arr->size++;
    }
    return OK;
}

int get_simple_num_arr(num_t *arr, int n)
{
    int *tmp;
    arr->arr = NULL;
    arr->size = 0;

    tmp = realloc(arr->arr, (arr->size + 1) * sizeof(int));
    if (tmp == NULL)
    {
        free(arr->arr);
        return ERROR_MEMORY;
    }

    arr->arr = tmp;
    arr->arr[arr->size] = 2;
    arr->size++;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            else if (i == j + 1)
            {
                tmp = realloc(arr->arr, (arr->size + 1) * sizeof(int));
                if (tmp == NULL)
                {
                    free(arr->arr);
                    return ERROR_MEMORY;
                }
                arr->arr = tmp;
                arr->arr[arr->size] = i;
                arr->size++;
            }
        }
    }
    return OK;
}

node_t *create_el(int el)
{
    node_t *new = malloc(sizeof(node_t));
    if (new)
    {
        new->exp = el;
        new->next = NULL;
    }
    return new;
}

node_t *push_list(node_t *head, node_t *new)
{
    node_t *cur = head;
    if (head == NULL)
        return new;
    
    while (cur->next)
        cur = cur->next;
    
    cur->next = new;
    return head;
}

node_t *read_num(void)
{
    int num;
    if (scanf("%d", &num) != 1)
        return NULL;
    if (num <= 0)
        return NULL;

    node_t *cur;
    node_t *head = NULL;

    int k = 0;
    int i = 2;
    for (k = 0; num % i == 0; k++)
        num /= i;
    cur = create_el(k);
    if (cur == NULL)
    {
        return NULL;
    }
    head = push_list(head, cur);

    for (int i = 2; i <= num; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            else if (i == j + 1)
            {
                for (k = 0; num % i == 0; k++)
                    num /= i;
                cur = create_el(k);
                if (cur == NULL)
                {
                    return NULL;
                }
                head = push_list(head, cur);
            }
        }
    }
    return head;
}

int multiplication(node_t **a, node_t **b, node_t **res)
{
    int error_code = ERROR_MEMORY;
    node_t *cur_a = *a;
    node_t *cur_b = *b;
    node_t *cur_res;

    for (; cur_a || cur_b;)
    {
        if (cur_a != NULL && cur_b != NULL)
        {
            cur_res = create_el(cur_a->exp + cur_b->exp);
            if (cur_res == NULL)
            {
                return error_code;
            }
            *res = push_list(*res, cur_res);

            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }
        else if (cur_a == NULL && cur_b != NULL)
        {
            cur_res = create_el(cur_b->exp);
            if (cur_res == NULL)
            {
                return error_code;
            }
            *res = push_list(*res, cur_res);
            cur_b = cur_b->next;
        }
        else if (cur_a != NULL && cur_b == NULL)
        {
            cur_res = create_el(cur_a->exp);
            if (cur_res == NULL)
            {
                return error_code;
            }
            *res = push_list(*res, cur_res);
            cur_a = cur_a->next;
        }
    }
    return OK;
}

void pop_back(node_t **head)
{
    if (head == NULL || *head == NULL)
        return;
    
    node_t *cur = *head;
    if (cur->next == NULL)
    {
        free(cur);
        (*head) = NULL;
        return;
    }
    
    node_t *prev = NULL;

    for (; cur; prev = cur, cur = cur->next)
        if (cur->next == NULL)
        {
            free(cur);
            prev->next = NULL;
            return;
        }
    return;
}

int del_zero(node_t **head)
{
    node_t *cur = *head;
    int size = 0;
    int zero_len = 0;
    for (; cur; cur = cur->next)
    {
        if (cur->exp == 0)
            zero_len++;
        else
            zero_len = 0;
        size++;
    }
    if (zero_len == size)
        return ERROR_LIST;

    for (int i = 0; i < zero_len; i++)
        pop_back(head);
    return OK;
}

int division(node_t **a, node_t **b, node_t **res)
{
    node_t *cur_a = *a;
    node_t *cur_b = *b;
    node_t *cur_res;

    int error_code = ERROR_MEMORY;

    for (; cur_a || cur_b;)
    {
        if (cur_a != NULL && cur_b != NULL)
        {
            if (cur_a->exp < cur_b->exp)
                return ERROR_DIV;
            cur_res = create_el(cur_a->exp - cur_b->exp);
            if (cur_res == NULL)
            {
                return error_code;
            }
            *res = push_list(*res, cur_res);
            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }
        else if (cur_a == NULL && cur_b != NULL)
            return ERROR_DIV_ZERO;
        else if (cur_a != NULL && cur_b == NULL)
        {
            cur_res = create_el(cur_a->exp);
            if (cur_res == NULL)
            {
                return error_code;
            }
            *res = push_list(*res, cur_res);
            cur_a = cur_a->next;
        }
    }
    error_code = del_zero(res);
    return error_code;
}


