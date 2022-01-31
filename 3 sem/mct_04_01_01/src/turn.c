#include "turn.h"
#include <stdlib.h>
#include <stdarg.h>

list_turn_t create_turn(void)
{
    list_turn_t new;
    new.head = malloc(sizeof(node_turn_t));
    if (new.head == NULL)
        return new;
    new.tail = malloc(sizeof(node_turn_t));
    if (new.tail == NULL)
    {
        free(new.head);
        return new;
    }
    new.head->next = new.tail;
    new.tail->next = NULL;
    new.head->head = NULL;
    new.tail->head = NULL;
    return new;
}

int push_stack(node_stack_t **head, int value)
{
    node_stack_t *new;
    new = malloc(sizeof(node_stack_t));
    if (new == NULL)
        return ERROR_MEMORY;
    new->next = *head;
    *head = new;
    (*head)->data = value;
    return OK;
}

void pop_stack(node_stack_t **head)
{
    node_stack_t *cur;
    cur = (*head)->next;
    free(*head);
    *head = cur;
}

int push(list_turn_t *turn, int el)
{
    int error_code = push_stack(&(turn->head->head), el);
    return error_code;
}

int peek(list_turn_t *turn)
{
    node_stack_t *cur = turn->head->head;
    return cur->data;
}

int pop(list_turn_t *turn)
{
    int n;
    n = peek(turn);
    pop_stack(&(turn->head->head));
    int error_code = push_stack(&(turn->tail->head), n);
    return error_code;
}

int push_turn(list_turn_t *turn, size_t n, ...)
{
    if (turn->head == NULL || n == 0)
        return ERROR_MEMORY;
    int error_code;
    va_list ptr;
    va_start(ptr, n);
    for (size_t i = 0; i < n; i++)
        error_code = push(turn, va_arg(ptr, int));
    va_end(ptr);
    return error_code;
}

int pop_turn(list_turn_t *turn, size_t n)
{
    if (turn->head == NULL || turn->tail == NULL || n == 0)
        return ERROR_MEMORY;
    int error_code;
    for (size_t i = 0; i < n; i++)
        error_code = pop(turn);
    return error_code;
}
