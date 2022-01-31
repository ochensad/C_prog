#include "list_func.h"
#include <stdlib.h>

void print_list(node_t *head, FILE *f)
{
    if (head == NULL)
        return;
    node_t *cur = head;

    for (; cur; cur = cur->next)
    {
        if (cur->next == NULL)
            fprintf(f, "%d", *(int*) cur->data);
        else
            fprintf(f, "%d ", *(int*) cur->data);
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

node_t *create_el(int *n)
{
    node_t *new = malloc(sizeof(node_t));
    if (new)
    {
        new->data = n;
        new->next = NULL;
    }
    return new;
}

node_t *get_list(set_t *arr)
{
    node_t *cur;
    node_t *new_head;
    
    for (size_t i = 0; i < arr->size; i++)
    {
        if (i == 0)
        {
            new_head = create_el(arr->arr + i);
            if (new_head == NULL)
            {
                free_list(new_head);
                free(arr->arr);
                return NULL;
            }
            cur = new_head;
        }
        else
        {
            cur->next = create_el(arr->arr + i);

            if (cur->next == NULL)
            {
                free_list(new_head);
                free(arr->arr);
                return NULL;
            }
            cur = cur->next;
        }
    }
    return new_head;
}

void insert_list(node_t **head, node_t *cur, node_t *prev, node_t *next)
{
    if (prev == NULL)
    {
        cur->next = next;
        *head = cur;
    }
    else
    {
        prev->next = cur;
        cur->next = next;
    }
}

int comparator(const void *a, const void *b)
{
    return *((int*) a) - *((int*) b);
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    node_t *cur = *head;
    node_t *prev = NULL;

    for (; cur; prev = cur, cur = cur->next)
        if (comparator(element->data, cur->data) < 0)
        {
            insert_list(head, element, prev, cur);
            return;
        }
    insert_list(head, element, prev, NULL);
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new_head = NULL;
    node_t *cur = head;
    node_t *next;

    for (; cur; cur = next)
    {
        next = cur->next;
        sorted_insert(&new_head, cur, comparator);
    }

    return new_head;
}

void *pop_front(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;
    
    node_t *new_head = (*head)->next;
    void *head_data = (*head)->data;

    free(*head);
    *head = new_head;
    return head_data;
}

void *pop_back(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;
    
    node_t *cur = *head;
    if (cur->next == NULL)
    {
        void *tail_data = cur->data;
        free(cur);
        (*head) = NULL;
        return tail_data;
    }
    
    node_t *prev = NULL;

    for (; cur; prev = cur, cur = cur->next)
        if (cur->next == NULL)
        {
            void *tail_data = cur->data;
            free(cur);
            prev->next = NULL;
            return tail_data;
        }
    return NULL;
}

void pop_list(node_t **head, node_t *el)
{
    node_t *cur = *head;
    node_t *prev = NULL;

    for (; cur; cur = cur->next)
    {
        if (cur == el)
        {
            prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
    }
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    if (head == NULL || *head == NULL)
        return;
    node_t *cur = *head;
    node_t *next = NULL;

    for (; cur;)
    {
        next = cur->next;
        if ((next != NULL) && comparator(cur->data, next->data) == 0)
            pop_list(head, next);
        else
            cur = cur->next;
    }
}

int list_task(node_t **head, void **min, void **max)
{
    if (*head == NULL)
        return ERROR_LIST;
    
    *head = sort(*head, comparator);

    remove_duplicates(head, comparator);

    *min = pop_front(head);
    if (*min == NULL)
        return OK;
    *max = pop_back(head);
    if (*max == NULL)
        return OK;

    return OK;
}