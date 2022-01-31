#include "addition.h"
#include "file_func.h"
#include "multiplication.h"
#include "determinant.h"

//Вычисление определителя с помощью разложения по строке

int main(int argc, char **argv)
{
    int action = 0;
    char file_name_1[NAME_LEN];
    char file_name_2[NAME_LEN];
    char file_res_name[NAME_LEN];

    int error_code = parse_argv(argc, argv, &action, file_name_1, file_name_2, file_res_name);

    if (error_code)
        return error_code;
    
    if (action == 1)
    {
        error_code = addition(file_name_1, file_name_2, file_res_name);
        return error_code;
    }
    else if (action == 2)
    {
        error_code = multiplication(file_name_1, file_name_2, file_res_name);
        return error_code;
    }
    else if (action == 3)
    {
        error_code = determinant(file_name_1, file_res_name);
        return error_code;
    }

    return OK;
}