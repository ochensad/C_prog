#include "str.h"


size_t my_strlen(const str_t *string)
{
    size_t len;

    for (len = 0; string[len] != '\0'; len++);
    
    return len;
}

const char *my_strrchr(const str_t *string, int symbol)
{
    size_t len = my_strlen(string);

    for (size_t i = len; i != 0; i -= 1)
        if (string[i] == symbol)
            return &string[i];
    if (string[0] == symbol)
        return &string[0];
    return NULL;
}

const char *my_strchr(const str_t *string, int symbol)
{
    size_t i;
    for (i = 0; string[i]; i++)
        if (string[i] == symbol)
            return &string[i];
    if (!string[i] && !symbol)
        return &string[i];
    return NULL;
}

const char *my_strpbrk(const str_t *str_1, const str_t *str_2)
{
    for (size_t i = 0; str_1[i] != '\0'; i++)
        for (size_t j = 0; str_2[j] != '\0'; j++)
            if (str_1[i] == str_2[j])
                return &str_1[i];
    return NULL;
}

size_t my_strspn(const str_t *str_1, const str_t *str_2)
{
    size_t counter = 0;
    size_t i;
    int flag;
    for (i = 0; str_1[i] != '\0'; i++)
    {
        flag = 1;
        for (size_t j = 0; str_2[j] != '\0' && flag == 1; j++)
            if (str_1[i] == str_2[j])
                flag = 0;
        if (flag == 1)
            return counter;
        else
            counter += 1;
    }
    return counter;
}

size_t my_strcspn(const str_t *str_1, const str_t *str_2)
{
    size_t counter = 0;
    size_t i;
    int flag;
    for (i = 0; str_1[i] != '\0'; i++)
    {
        flag = 1;
        for (size_t j = 0; str_2[j] != '\0' && flag == 1; j++)
            if (str_1[i] == str_2[j])
                flag = 0;
        if (flag == 1)
            counter += 1;
        else
            return counter;
    }
    return counter;
}