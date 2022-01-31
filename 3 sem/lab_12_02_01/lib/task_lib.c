#include "task_lib.h"
#include <stdio.h>
#include <string.h>

size_t find_neg(const int *pstart, const int *pend)
{
    size_t i = 0;
    while (pstart < pend)
    {
        if (*(pstart++) < 0)
            return i;
        i++;
    }
    return i;
}

void copy_el(const int *ps_src, int **ps_dst, int **pe_dst, size_t count)
{
    int *ps_d = *ps_dst;
    
    for (size_t i = 0; i < count; i++)
    {
        *(ps_d++) = *ps_src;
        ps_src++;
    }
    *pe_dst = ps_d;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        return -1;
    
    size_t num_of_neg = 0;

    num_of_neg = find_neg(pb_src, pe_src);

    if (num_of_neg == 0)
        return -1;
    
    copy_el(pb_src, pb_dst, pe_dst, num_of_neg);

    return 0;
}

int swap(void *a, void *b, size_t size, char *buf)
{
    memcpy(&buf, a, size);
    memcpy(a, b, size);
    memcpy(b, &buf, size);
    return 0;
}

void mysort(void *arr, size_t count, size_t size, int (*greater)(const void*, const void*))
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
}

