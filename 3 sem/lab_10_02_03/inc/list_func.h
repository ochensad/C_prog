#ifndef LIST_FUNC
#define LIST_FUNC

#include "errors.h"
#include "struct.h"

void free_list(node_t *head);
void print_list(node_t *head);
node_t *read_num(void);
int multiplication(node_t **a, node_t **b, node_t **res);
int division(node_t **a, node_t **b, node_t **res);

int get_num_arr(int n, num_t *arr);
int get_simple_num_arr(num_t *arr, int n);
#endif