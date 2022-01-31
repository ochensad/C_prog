#include "student.h"
#include "struct.h"

student_t get_struct_by_pos(FILE *f, int i)
{
    student_t student;
    fseek(f, i * sizeof (student_t), SEEK_SET);
    fread(&student, sizeof (student_t), 1, f);
    fseek(f, 0L, SEEK_SET);
    return student;
}

int put_struct_by_pos(FILE *f, student_t student, int i)
{
    fseek(f, i * sizeof (student_t), SEEK_SET);
    fwrite(&student, sizeof (student_t), 1, f);
    return SUCCESS;
}

int compare(student_t comp)
{
    student_t ivanov = { .name = "Иванов", .num = 4};
    student_t petrov = { .name = "Петров", .num = 5};

    if (strcmp(comp.name, ivanov.name) > 0 && strcmp(petrov.name, comp.name) > 0)
        return 1;
    return 0;
}
