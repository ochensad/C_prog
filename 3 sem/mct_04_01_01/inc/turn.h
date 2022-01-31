#ifndef MY_TURN
#define MY_TURN

#include "errors.h"
#include "struct.h"
#include <stdio.h>

int pop_turn(list_turn_t *turn, size_t n);
int push_turn(list_turn_t *turn, size_t n, ...);
list_turn_t create_turn(void);
#endif