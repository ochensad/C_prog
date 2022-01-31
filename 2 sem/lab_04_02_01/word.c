#include <stdio.h>
#include <string.h>

#include "word.h"

#define FIRST_LESS 5
#define SECOND_LESS 6

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

int is_word_unique(word_t word, str_arr_t s_arr, size_t *n)
{
    int flag = 0;
    size_t i = 0;

    if (word[0] == '\0')
        flag = 1;
    
    while (i < *n && flag == 0)
    {
        if (strcmp(s_arr[i], word) == 0)
            flag = 1;
        i += 1;
    }
    return flag;
}

int append_word(word_t word, str_arr_t s_arr, size_t *n)
{
    strcpy(s_arr[*n], word);
    *n += 1;
    return EXIT_SUCCESS;
}

int add_letter(word_t word, size_t num_of_letter, str_t s, size_t i)
{
    word[num_of_letter] = s[i];
    word[num_of_letter + 1] = '\0';
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
            add_letter(word, num_of_letter, s, i);
            num_of_letter += 1;
            if (num_of_letter >= WORD_MAX)
                return EXIT_INVALID_LEN;
        }
        else
        {
            if (word[0] != '\0')
            {
                int flag_1 = is_word_unique(word, s_arr, num_of_word);
                if (flag_1 == 0)
                    append_word(word, s_arr, &*num_of_word);
            }
            num_of_letter = 0;
            word[num_of_letter] = '\0';
        }   
    }
    return EXIT_SUCCESS;
}
int compare(str_arr_t s_arr, size_t first, size_t second)
{
    if (strcmp(s_arr[first], s_arr[second]) < 0)
        return FIRST_LESS;
    
    return SECOND_LESS;
} 

int swap(str_arr_t s_arr, size_t first, size_t second)
{
    word_t t;
    
    strcpy(t, s_arr[first]);
    strcpy(s_arr[first], s_arr[second]);
    strcpy(s_arr[second], t);

    return EXIT_SUCCESS;
}

int bubble_sort(str_arr_t s_arr, size_t num_of_word)
{
    for (size_t i = 0; i < num_of_word - 1; i++)
        for (size_t j = 0; j < num_of_word - 1 - i; j++)
            if (compare(s_arr, j, j + 1) == SECOND_LESS)
                swap(s_arr, j, j + 1);
    return EXIT_SUCCESS;
}

int join(str_t s, str_arr_t s_arr, size_t num_of_word)
{
    s[0] = '\0';
    for (size_t i = 0; i < num_of_word; i++)
    {
        strcat(s, s_arr[i]);
        
        if (i < num_of_word - 1)
            strcat(s, " ");
    }
    return EXIT_SUCCESS;
}

