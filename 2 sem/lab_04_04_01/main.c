#include <stdio.h>

#include "word.h"

int main(void)
{
    str_t s;
    int s_error = read_str(s);
    if (s_error == EXIT_INVALID_LEN)
        return EXIT_INVALID_LEN;
    if (s_error == EXIT_ZERO_LEN)
    {
        printf("NO");
        return EXIT_SUCCESS;
    }
    if (find_num(s) == YES)
        printf("YES");
    if (find_num(s) == NO)
        printf("NO");
    return EXIT_SUCCESS;
}