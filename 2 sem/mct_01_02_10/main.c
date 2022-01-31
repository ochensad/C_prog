# include <stdio.h>
# include <stdlib.h>

# define NMAX 1024
# define MYMAX 10
# define EXIT_INVALID_LEN 2
# define EXIT_INVALID_NUMBERS 3

int input(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (scanf("%d", arr + i) != 1)
			return EXIT_INVALID_NUMBERS;
	}
	return EXIT_SUCCESS;
}

size_t remove_arr(int arr[], size_t len)
{
	size_t i = 0;
	size_t flag = 0;
	while (i < len)
	{
		flag = 0;
		int last_el = 0;
		while (last_el <= arr[i])
		{
			if (last_el == arr[i])
				flag = 1;
			int now_el = last_el * 2 + 1;
			last_el = now_el;
		}
		if (flag)
		{
			for (size_t j = i + 1; j < len; j++)
				arr[j - 1] = arr [j];
			len--;
		}
		else
			i++;
	}
	return len;
}

int output(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("%d ", arr[i]);
	return EXIT_SUCCESS;
}

int main(void)
{
	int a[NMAX];
	size_t n;
	size_t n_01 = 0;
	
	if (scanf("%zu", &n) != 1 || n <=0)
		return EXIT_INVALID_LEN;
	
	input(a, n);
	n_01 = remove_arr(a, n);

	if (n_01 == 0)
		return EXIT_INVALID_LEN;
	output(a, n_01);
	return EXIT_SUCCESS;
}