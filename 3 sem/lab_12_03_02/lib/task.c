
int is_prime(int num)
{
    for (int j = 2; j < num; j++)
        if (num % j == 0)
            return 1;
    return 0;
}

void fill_array_with_prime(int *arr, int size)
{
    int prime = 2;
    int flag = 1;

    for (int i = 0; i < size; i++)
    {
        arr[i] = prime;
        flag = 1;
        while (flag)
        {
            prime++;
            flag = is_prime(prime);
        }
    }
}

int fill_narr_with_even_aft(int *arr_src, int len_src, int *arr_dst, int len_dst, int add_num)
{
    int count_add_elems = 0;
    for (int i = 0; i < len_src; i++)
    {
        if (count_add_elems < len_dst)
        {
            arr_dst[count_add_elems] = arr_src[i];
            count_add_elems++;
            if (arr_src[i] % 2 == 0)
                if (count_add_elems < len_dst)
                {
                    arr_dst[count_add_elems] = add_num;
                    count_add_elems++;
                }
        }
    }
    return count_add_elems;
}