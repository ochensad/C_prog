#ifndef MY_STRUCT
#define MY_STRUCT

#include <stdio.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct
{
    int *arr;
    size_t size;
} set_t;


#endif