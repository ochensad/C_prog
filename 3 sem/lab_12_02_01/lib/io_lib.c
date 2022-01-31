#include "io_lib.h"

LIB_DLL int LIB_DECL file_size(FILE *f, size_t *size)
{
    int buf;
    int er_flag = 1;
    while (er_flag == 1)
    {
        er_flag = fscanf(f, "%d", &buf);
        if (er_flag == 0)
            return -1;
        if (er_flag != EOF)
            *size += 1;
    }
    return 0;
}

LIB_DLL int LIB_DECL file_read(FILE *f, int *pstart, int *pend)
{
    if (fseek(f, 0, SEEK_SET))
        return -1;

    int er_flag = 1;

    while (pstart < pend)
    {
        er_flag = fscanf(f, "%d", pstart);
        if (er_flag == 0)
            return -1;
        
        pstart++;
    }
    return 0;
}

LIB_DLL void LIB_DECL file_write(FILE *f, int *pstart, int *pend)
{
    int *ps = pstart;
    int *pe = pend;

    while (ps < pe)
        fprintf(f, "%d ", *(ps++));
}


