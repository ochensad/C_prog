# include "my_func.h"

int main(void)
{
    FILE * f = stdin;

    size_t counter = 0;

    if (count_neighbors(f, &counter) == PROCESS_ERROR)
        return PROCESS_ERROR;
    printf("%zu", counter);
    return SUCCESS_PROCESS;
}