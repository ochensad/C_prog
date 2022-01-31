#ifndef MY_STRUCT
#define MY_STRUCT

#include <inttypes.h>

#define NAME_LEN 30
#define PRODUCER_LEN 15

typedef char name_t[NAME_LEN + 1];
typedef char producer_t[PRODUCER_LEN + 1];
typedef uint32_t price_t;
typedef uint32_t amount_t;

typedef struct
{
    name_t name;
    producer_t produser;
    price_t price;
    amount_t amount;
} product_t;

#endif