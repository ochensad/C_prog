#include "my_file.h"

int get_char_dict(char *str, char *dict)
{
    size_t j = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (strchr(dict, str[i]) == NULL)
        {
            dict[j] = str[i];
            dict[j + 1] = '\0';
            j++;
        }
    }
    return OK;
}

int a_i(char *s_src, char *s_dst)
{
    char dict[MAX_LEN + 1] = "\0";
    char s_dst_copy[MAX_LEN + 1];
    get_char_dict(s_src, dict);
    size_t i, j, k;

    strcpy(s_dst_copy, s_dst);
    for (k = 0; dict[k] != '\0'; k++)
    {
        for (i = j = 0; s_dst_copy[i] != '\0'; i++)
            if (s_dst_copy[i] != dict[k])
                s_dst_copy[j++] = s_dst_copy[i];
        s_dst_copy[j] = '\0';
    }
    if (s_dst_copy[0] == '\0')
        return EMPTY_STR;
    if (find_pol(s_dst_copy) == 1)
        return YES;
    return NO;
}

int find_pol(char *s)
{
    size_t i = strlen(s);

    int flag = 1;
    for (size_t j = 0; (j < i / 2) && flag == 1; j++)
    {
        if (s[j] != s[i - j - 1])
            flag = 0;
    }
    return flag;
}
