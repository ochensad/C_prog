#ifndef LIST_FUNC
#define LIST_FUNC

#include "errors.h"
#include "struct.h"

void free_list(node_t *head);
node_t *get_list(set_t *arr);
int list_task(node_t **head, void **min, void **max);
void print_list(node_t *head, FILE *f);


void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));
void *pop_back(node_t **head);
void *pop_front(node_t **head);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
int comparator(const void *a, const void *b);

#endif