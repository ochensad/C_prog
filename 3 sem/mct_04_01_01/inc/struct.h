#ifndef MY_STRUCT
#define MY_STRUCT

typedef struct node_stack
{
    int data;
    struct node_stack *next;
} node_stack_t;

typedef struct node_turn
{
    node_stack_t *head;
    struct node_turn *next;
} node_turn_t;

typedef struct
{
    node_turn_t *head;
    node_turn_t *tail;
} list_turn_t;

#endif