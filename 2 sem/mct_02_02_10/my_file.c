#include "my_file.h"
#include "struct.h"
#include "student.h"

int size_of_file(FILE *f, long *size)
{
    long size_of_st;

    if (fseek(f, 0L, SEEK_END))
        return ERROR_READING_FILE;
    size_of_st = ftell(f);
    if (size_of_st < 0)
        return ERROR_SIZE_OF_FILE;
  
    *size = size_of_st / sizeof(student_t);
    fseek(f, 0L, SEEK_SET);
    return OK;
}

int delete_st(FILE *f)
{
    long size;
    student_t student;
    student_t del_el = { .name = "0000", .num = 0};

    if (size_of_file(f, &size) || size == 0)
        return ERROR_SIZE_OF_FILE;

    if (size == 1)
        return OK;
    
    fseek(f, 0L, SEEK_END);
    fwrite(&del_el, sizeof (student_t), 1, f);
    fseek(f, 0L, SEEK_SET);

    int i = 0;
    int flag = 1;
    while (i <= size && flag == 1)
    {
        student = get_struct_by_pos(f, i);
        if (strcmp(student.name, "0000") == 0)
            flag = 0;
        if (compare(student) > 0)
        {
            del_el = get_struct_by_pos(f, i);
            for (int j = i; j < size; j++)
                put_struct_by_pos(f, get_struct_by_pos(f, j + 1), j);
            put_struct_by_pos(f, del_el, size);
        }
        else
            i++;
    }
    return OK;
}