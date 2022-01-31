#include <stdio.h>
#include <string.h>

#include "str.h"

int main(void)
{
    char s_1[TEST_NUM][STR_MAX + 1] = { "Hello, world!", " ", "Hi! How are you?", "They say, the winter will be cold.","It is raining.","Hope" };
    char s_2[TEST_NUM][STR_MAX + 1] = { "wo","are","."," ","b","aouye" };
    int smb[TEST_NUM] = { 'z','5','a','y','i','o' };
    printf(".....STRRCHR.....\n");
    for (size_t i = 0; i < TEST_NUM; i++)
    {
        if (my_strrchr(s_1[i], smb[i]) != strrchr(s_1[i], smb[i]))
            printf("Test %zu not passed\n", i + 1);
        else
            printf("Test %zu passed\n", i + 1);
    }
    printf(".....STRCHR.....\n");
    for (size_t i = 0; i < TEST_NUM; i++)
    {
        if (my_strchr(s_1[i], smb[i]) != strchr(s_1[i], smb[i]))
            printf("Test %zu not passed\n", i + 1);
        else
            printf("Test %zu passed\n", i + 1);
    }

    printf(".....STRPBRK.....\n");
    for (size_t i = 0; i < TEST_NUM; i++)
    {
        if (my_strpbrk(s_1[i], s_2[i]) != strpbrk(s_1[i], s_2[i]))
            printf("Test %zu not passed\n", i + 1);
        else
            printf("Test %zu passed\n", i + 1);
    }

    printf(".....STRSPN.....\n");
    for (size_t i = 0; i < TEST_NUM; i++)
    {
        if (my_strspn(s_1[i], s_2[i]) != strspn(s_1[i], s_2[i]))
            printf("Test %zu not passed\n", i + 1);
        else
            printf("Test %zu passed\n", i + 1);
    }
    printf(".....STRCSPN.....\n");
    for (size_t i = 0; i < TEST_NUM; i++)
    {
        if (my_strcspn(s_1[i], s_2[i]) != strcspn(s_1[i], s_2[i]))
            printf("Test %zu not passed\n", i + 1);
        else
            printf("Test %zu passed\n", i + 1);
    }
    return EXIT_SUCCESS;
}