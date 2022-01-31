#include <stdio.h>

#include "word.h"

int main(void)
{
    str_t s;
    word_t punct_marks = ",:;.!? -";
    str_arr_t s_arr;
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
    bubble_sort(s_arr, num_of_words);
    join(s, s_arr, num_of_words);
    printf("Result: %s", s);
    return EXIT_SUCCESS;   
}