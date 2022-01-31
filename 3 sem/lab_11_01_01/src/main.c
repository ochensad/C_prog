#include "my_snprintf.h"
#include <limits.h>

int main(void)
{
    char buf[BUF_SIZE + 1];
    char my_buf[BUF_SIZE + 1];

    char s[] = "abcd";
    long int d = 44;
    int my_n = my_snprintf(my_buf, BUF_SIZE, "%c k %s %ld %x %o %i ", 'g', s, d, 15, UINT_MAX, 65);
    int n = snprintf(buf, BUF_SIZE, "%c k %s %ld %x %o %i ", 'g', s, d, 15, UINT_MAX, 65);
    

    printf("%d, %s\n", n, buf);
    printf("%d, %s\n", my_n, my_buf);
    return OK;
}