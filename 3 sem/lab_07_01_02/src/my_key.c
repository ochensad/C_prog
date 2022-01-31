#include "my_key.h"

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
        return ERROR_DATA;
    
    size_t num_of_neg = 0;

    num_of_neg = find_neg(pb_src, pe_src);

    if (num_of_neg == 0)
        return ERROR_NO_EL_IN_ARRAY;

    *pb_dst = malloc(num_of_neg * sizeof(int));

    if (*pb_dst == NULL)
        return ERROR_MEMORY;
    
    copy_el(pb_src, pb_dst, pe_dst, num_of_neg);

    return OK;
}