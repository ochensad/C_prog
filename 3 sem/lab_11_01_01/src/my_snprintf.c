#include "my_snprintf.h"
#include <limits.h>

int convert_char_to_stream(char **stream_s, char *stream_e, char el)
{
    if (*stream_s < stream_e)
    {
        *((*stream_s)++) = el;
    }
    return 1;
}

int convert_str_to_stream(char **stream_s, char *stream_e, char *el)
{
    int n = 0;

    for (size_t i = 0; el[i] != '\0'; i++)
    {
        convert_char_to_stream(stream_s, stream_e, el[i]);
        n++;
    }
    return n;
}

int num_len(int n)
{
    int len = 1;

    for (; n > 9; len++)
        n /= 10;
    
    return len;
}

int num_len_long(long int n)
{
    int len = 1;

    for (; n > 9; len++)
        n /= 10;
    
    return len;
}

int convert_decimal_long_to_stream(char **stream_s, char *stream_e, long int num)
{
    int n = 0;
    int min_flag = 0;
    if (num < 0)
    {
        n = convert_char_to_stream(stream_s, stream_e, '-');
        if (num != LONG_MIN)
        {
            num *= -1;
        }
        else
        {
            num += 1;
            num *= -1;
            min_flag = 1;
        }
    }
    int len = num_len_long(num);

    long int a[len];
    for (int i = 0; i < len; i++)
    {
        a[len - i - 1] = num % (long)10;
        num /= (long)10;
    }
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1 && min_flag == 1)
            n += convert_char_to_stream(stream_s, stream_e, (a[i] + 1) + '0');
        else
            n += convert_char_to_stream(stream_s, stream_e, a[i] + '0');
    }
    return n;
}

int convert_dec_short_to_stream(char **stream_s, char *stream_e, short int num)
{
    int n = 0;
    int min_flag = 0;
    if (num < 0)
    {
        n = convert_char_to_stream(stream_s, stream_e, '-');
        if (num != SHRT_MIN)
        {
            num *= -1;
        }
        else
        {
            num += 1;
            num *= -1;
            min_flag = 1;
        }
    }
    int len = num_len(num);

    int a[len];
    for (int i = 0; i < len; i++)
    {
        a[len - i - 1] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1 && min_flag == 1)
            n += convert_char_to_stream(stream_s, stream_e, (a[i] + 1) + '0');
        else
            n += convert_char_to_stream(stream_s, stream_e, a[i] + '0');
    }
    return n;
}

int convert_decimal_to_stream(char **stream_s, char *stream_e, int num)
{
    int n = 0;
    int min_flag = 0;
    if (num < 0)
    {
        n = convert_char_to_stream(stream_s, stream_e, '-');
        if (num != INT_MIN)
        {
            num *= -1;
        }
        else
        {
            num += 1;
            num *= -1;
            min_flag = 1;
        }
    }
    int len = num_len(num);

    int a[len];
    for (int i = 0; i < len; i++)
    {
        a[len - i - 1] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1 && min_flag == 1)
            n += convert_char_to_stream(stream_s, stream_e, (a[i] + 1) + '0');
        else
            n += convert_char_to_stream(stream_s, stream_e, a[i] + '0');
    }
    return n;
}

int convert_num(unsigned num, unsigned sys, unsigned arr[])
{
    int i = 0;
    for (; num >= sys; i++, num /= sys)
        arr[i] = num % sys;
    arr[i] = num % sys;
    i++;
    return i;
}

int convert_octal_to_stream(char **stream_s, char *stream_e, unsigned num)
{
    int n = 0;

    unsigned arr[MAX_ARR_OCT_LEN];
    n = convert_num(num, 8, arr);

    for (int i = 0; i < n; i++)
        convert_char_to_stream(stream_s, stream_e, arr[n - i - 1] + '0');
    return n;
}

int convert_num_long(long unsigned num, long unsigned sys, unsigned arr[])
{
    int i = 0;
    for (; num >= sys; i++, num /= sys)
        arr[i] = num % sys;
    arr[i] = num % sys;
    i++;
    return i;
}

int convert_octal_long_to_stream(char **stream_s, char *stream_e, long unsigned num)
{
    int n = 0;

    unsigned arr[MAX_ARR_OCT_LONG_LEN];
    n = convert_num_long(num, 8, arr);

    for (int i = 0; i < n; i++)
        convert_char_to_stream(stream_s, stream_e, arr[n - i - 1] + '0');
    return n;
}

int convert_octal_short_to_stream(char **stream_s, char *stream_e, short unsigned num)
{
    int n = 0;

    unsigned arr[MAX_ARR_OCT_LONG_LEN];
    n = convert_num(num, 8, arr);

    for (int i = 0; i < n; i++)
        convert_char_to_stream(stream_s, stream_e, arr[n - i - 1] + '0');
    return n;
}

int convert_hex_to_stream(char **stream_s, char *stream_e, unsigned num)
{
    int n = 0;
    
    unsigned arr[MAX_ARR_HEX_LEN];
    char hex_arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    n = convert_num(num, 16, arr);

    for (int i = 0; i < n; i++)
    {
        if (arr[n - i - 1] < 10)
            convert_char_to_stream(stream_s, stream_e, arr[n - i - 1] + '0');
        else
            convert_char_to_stream(stream_s, stream_e, hex_arr[(arr[n - i - 1]) - 10]);
    }
    return n;
}

int convert_hex_long_to_stream(char **stream_s, char *stream_e, long unsigned num)
{
    int n = 0;
    
    unsigned arr[MAX_ARR_HEX_LEN];
    char hex_arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    n = convert_num_long(num, 16, arr);

    for (int i = 0; i < n; i++)
    {
        if (arr[n - i - 1] < 10)
            convert_char_to_stream(stream_s, stream_e, arr[n - i - 1] + '0');
        else
            convert_char_to_stream(stream_s, stream_e, hex_arr[(arr[n - i - 1]) - 10]);
    }
    return n;
}

int convert_hex_short_to_stream(char **stream_s, char *stream_e, short unsigned num)
{
    int n = 0;
    
    unsigned arr[MAX_ARR_HEX_LEN];
    char hex_arr[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    n = convert_num(num, 16, arr);

    for (int i = 0; i < n; i++)
    {
        if (arr[n - i - 1] < 10)
            convert_char_to_stream(stream_s, stream_e, arr[n - i - 1] + '0');
        else
            convert_char_to_stream(stream_s, stream_e, hex_arr[(arr[n - i - 1]) - 10]);
    }
    return n;
}


int my_snprintf(char *stream, size_t n, const char *format, ...)
{
    va_list ptr;

    va_start(ptr, format);

    char *stream_e = stream + n;
    int count_numb_add_elems = 0;
    
    while (*format != '\0')
    {
        if (*format == '%')
        {
            if (*(format + 1) == 's')
            {
                char *s = va_arg(ptr, char*);
                count_numb_add_elems += convert_str_to_stream(&stream, stream_e, s);
            }
            else if (*(format + 1) == 'c')
            {
                char c = va_arg(ptr, int);
                count_numb_add_elems += convert_char_to_stream(&stream, stream_e, c);
            }
            else if (*(format + 1) == 'd' || *(format + 1) == 'i')
            {
                int num = va_arg(ptr, int);
                count_numb_add_elems += convert_decimal_to_stream(&stream, stream_e, num);
            }
            else if (*(format + 1) == 'l')
            {
                if (*(format + 2) == 'd' || *(format + 2) == 'i')
                {
                    long int num = va_arg(ptr, long int);
                    count_numb_add_elems += convert_decimal_long_to_stream(&stream, stream_e, num);
                    format++;
                }
                else if (*(format + 2) == 'o')
                {
                    long unsigned int num = va_arg(ptr, long unsigned);
                    count_numb_add_elems += convert_octal_long_to_stream(&stream, stream_e, num);
                    format++;
                }
                else if (*(format + 2) == 'x')
                {
                    long unsigned int num = va_arg(ptr, long unsigned);
                    count_numb_add_elems += convert_hex_long_to_stream(&stream, stream_e, num);
                    format++;
                }
                else
                {
                    count_numb_add_elems += convert_char_to_stream(&stream, stream_e, *format);
                }
            }
            else if (*(format + 1) == 'h')
            {
                if (*(format + 2) == 'd' || *(format + 2) == 'i')
                {
                    short int num = va_arg(ptr, int);
                    count_numb_add_elems += convert_dec_short_to_stream(&stream, stream_e, num);
                    format++;
                }
                else if (*(format + 2) == 'o')
                {
                    short unsigned int num = va_arg(ptr, unsigned);
                    count_numb_add_elems += convert_octal_short_to_stream(&stream, stream_e, num);
                    format++;
                }
                else if (*(format + 2) == 'x')
                {
                    short unsigned int num = va_arg(ptr, unsigned);
                    count_numb_add_elems += convert_hex_short_to_stream(&stream, stream_e, num);
                    format++;
                }
                else
                {
                    count_numb_add_elems += convert_char_to_stream(&stream, stream_e, *format);
                }
            }
            else if (*(format + 1) == 'o')
            {
                unsigned num = va_arg(ptr, unsigned);
                count_numb_add_elems += convert_octal_to_stream(&stream, stream_e, num);
            }
            else if (*(format + 1) == 'x')
            {
                unsigned num = va_arg(ptr, unsigned);
                count_numb_add_elems += convert_hex_to_stream(&stream, stream_e, num);
            }
            format++;
        }
        else
            count_numb_add_elems += convert_char_to_stream(&stream, stream_e, *format);
        format++;
    }

    if (stream < stream_e)
        *stream = '\0';
    else if (n > 0)
        *(--stream) = '\0';
    
    va_end(ptr);
    return count_numb_add_elems;
}