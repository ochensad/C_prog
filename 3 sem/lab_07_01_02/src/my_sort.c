#include "my_sort.h"

int greater(const void *a, const void *b)
{
    const int *left = a;
    const int *right = b;
    
    return *left - *right;
}

int swap(void *a, void *b, size_t size, char *buf)
{
    memcpy(&buf, a, size);
    memcpy(a, b, size);
    memcpy(b, &buf, size);
    return OK;
}

int mysort(void *arr, size_t count, size_t size, int (*greater)(const void*, const void*))
{
    char *pstart = arr;
    char *pend = pstart + (count - 1) * size;
    char buf [200];

    size_t i = 0;
    for (; pstart < pend; pstart += size)
    {
        char *pend_j = pstart + (count - i - 1) * size;
        for (char *pstart_j = arr; pstart_j < pend_j; pstart_j += size)
            if (greater(pstart_j, pstart_j + size) > 0)
                swap(pstart_j, pstart_j + size, size, buf);
        i++;
    }
    return OK;
}