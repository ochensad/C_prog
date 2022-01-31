# include "my_func.h"

int count_neighbors(FILE *f, size_t *count)
{
    int left, right, center;
    size_t flag = 0;
    
    if (fscanf(f, "%d", &left) == 1)
    {
        if (fscanf(f, "%d", &center) == 1)
            while (fscanf(f, "%d", &right) == 1)
            {
                flag = 1;
                if (center > right && center > left)
                    *count += 1;
                left = center;
                center = right;
            }
        else
            return PROCESS_ERROR;
    }
    else
        return PROCESS_ERROR;
    if (flag)
        return SUCCESS_PROCESS;
    return PROCESS_ERROR;
}