#include <stdio.h>
#include <string.h>

#include "word.h"

int main(void)
{
    str_t s;
    word_t punct_marks = ",:;.!? -";
    str_arr_t s_arr;
    str_t new_str;
    size_t num_of_words = 0;
    
    int s_error = read_str(s);
    if (s_error == EXIT_INVALID_LEN)
        return EXIT_INVALID_LEN;
    if (s_error == EXIT_ZERO_LEN)
        return EXIT_ZERO_LEN;

    if (split(s, punct_marks, s_arr, &num_of_words))
        return EXIT_INVALID_LEN;

    if (num_of_words == 0)
        return NO_WORDS_ERROR;

    join(new_str, s_arr, num_of_words);
    if (strlen(new_str) == 0)
        return EXIT_INVALID_LEN;
        
    printf("Result: %s\n", new_str);
    return EXIT_SUCCESS;
}