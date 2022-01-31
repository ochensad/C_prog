#include "my_sort.h"
#include "file_func.h"

// Вариант сортировки 5
// Вариант фильтрации 2

int main(int argc, char **argv)
{
    int filter_mode = 0;
    int error_code = check_argv(argc, argv, &filter_mode);

    if (error_code)
        return error_code;
    
    size_t f_size = 0;
    
    int *arr = NULL;

    error_code = get_array_to_sort(argv[1], filter_mode, &arr, &f_size);

    if (error_code)
        return error_code;

    mysort(arr, f_size, sizeof(int), greater);

    error_code = file_write(argv[2], arr, arr + f_size);

    if (error_code)
    {
        free(arr);
        return error_code;
    }

    free(arr);
    return error_code;
}