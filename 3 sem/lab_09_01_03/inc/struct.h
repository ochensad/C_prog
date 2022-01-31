#ifndef MY_STRUC
#define MY_STRUC

#include <inttypes.h>
#define MAX_PRICE_LEN 26

typedef uint32_t price_t;

typedef struct
{
    char *name;
    price_t price;
} product_t;

#endif