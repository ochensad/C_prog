#ifndef MY_STRUC
#define MY_STRUC

#include <inttypes.h>

#define MAX_LEN 26

typedef char name_t[MAX_LEN + 1];
typedef uint32_t price_t;

typedef struct
{
    name_t name;
    price_t price;
} product_t;

#endif