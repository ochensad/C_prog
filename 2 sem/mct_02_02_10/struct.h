#ifndef MY_STRUCT
#define MY_STRUCT

#include <inttypes.h>
#define NAME_LEN 125

typedef char name_t[NAME_LEN + 1];
typedef uint64_t num_t;

typedef struct
{
  name_t name;
  num_t num;
} student_t;

#endif