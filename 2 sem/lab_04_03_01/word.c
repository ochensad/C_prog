#include <string.h>
#include <stdio.h>

#include "word.h"

#define THE_SAME 5
#define DIFFERENT 6

int read_str(str_t s)
{
    int ch;
    size_t len = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (len < STR_MAX)
            s[len++] = ch;
        else
            return EXIT_INVALID_LEN;
    if (len == 0)
        return EXIT_ZERO_LEN;
    s[len] = '\0';
    return EXIT_SUCCESS;
}

int append_word(word_t word, str_arr_t s_arr, size_t *n)
{
    strcpy(s_arr[*n], word);
    *n += 1;
    return EXIT_SUCCESS;
}

int add_letter(word_t word, size_t *num_of_letter, str_t s, size_t i)
{
    word[*num_of_letter] = s[i];
    word[*num_of_letter + 1] = '\0';
    *num_of_letter += 1;
    if (*num_of_letter > WORD_MAX)
        return EXIT_INVALID_LEN;
    return EXIT_SUCCESS;
}

int split(str_t s, word_t punct_marks, str_arr_t s_arr, size_t *num_of_word)
{
    size_t len = strlen(s);
    size_t i, j, num_of_letter = 0;
    size_t flag = 0;

    char word[WORD_MAX];
    word[0] = '\0';
    for (i = 0; i <= len; i++)
    {
        j = 0;
        flag = 0;
        while (punct_marks[j] != '\0' && flag == 0)
            if (s[i] == punct_marks[j++])
                flag = 1;
        
        if (flag == 0 && s[i] != '\0')
        {
            if (add_letter(word, &num_of_letter, s, i))
                return EXIT_INVALID_LEN;
        }
        else
        {
            if (word[0] != '\0')
                append_word(word, s_arr, &*num_of_word);
            
            num_of_letter = 0;
            word[num_of_letter] = '\0';
        }   
    }
    return EXIT_SUCCESS;
}

int compare(str_arr_t s_arr, size_t first, size_t second)
{
    if (strcmp(s_arr[first], s_arr[second]) == 0)
        return THE_SAME;
    return DIFFERENT;
}
int delite_letters(str_t s)
{
    size_t i = strlen(s) - 1;

    while (i != 0)
    {
        while (strchr(s, s[i]) != strrchr(s, s[i]))
        {
            for (size_t j = i; s[j] != '\0'; j++)
                s[j] = s[j + 1];
        }
        i--;
    }
    return EXIT_SUCCESS;
}
int join(str_t s, str_arr_t s_arr, size_t num_of_word)
{
    size_t i = num_of_word - 1;
    s[0] = '\0';
    size_t flag = 0;
    while (i >= 1)
    {
        i -= 1;
        if (compare(s_arr, i, num_of_word - 1) == DIFFERENT)
        {
            delite_letters(s_arr[i]);
            if (flag)
                strcat(s, " ");
            strcat(s, s_arr[i]);
            flag = 1;
        }
    }
    return EXIT_SUCCESS;
}