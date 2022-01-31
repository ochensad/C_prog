# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <math.h>

# define EXIT_NOT_ENOUGH_NUMBERS 2
# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 1024
# define MYMAX 10

int input(int arr[], size_t len)
{
	int eof_test;
	for (size_t i = 0; i < len; i++)
	{
		if ((eof_test = scanf("%d", arr + i)) != 1)
		{
			if (eof_test == EOF)
				return EXIT_NOT_ENOUGH_NUMBERS;
			return EXIT_INVALID_NUMBERS;
		}
	}
	return EXIT_SUCCESS;
}

size_t rewriting(int arr[], size_t len)
{
	size_t i = 0;

	while (i < len)
	{
		int palindr[NMAX];
		int num = arr[i];
		size_t len_p = 0;

		while (num > 0)
		{
			palindr[len_p] = (num % 10);
			num /= 10;
			len_p++;
		}

		size_t flag = 1;
		for (size_t j = 0; j < (len_p / 2); j++)
			if (palindr[j] != palindr[len_p - 1 - j])
				flag = 0;
		
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
	size_t len = 0;

	int input_error;
	size_t len_01 = 0;

	if (scanf("%zu", &len) != 1 || len <= 0 || len > MYMAX)
		return EXIT_INVALID_LEN;
	
	input_error = input(a, len);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	else if (input_error == EXIT_NOT_ENOUGH_NUMBERS)
		return EXIT_NOT_ENOUGH_NUMBERS;
  
	len_01 = rewriting(a, len);

	if (len_01 == 0)
		return EXIT_INVALID_LEN; 

	output(a, len_01);
	return EXIT_SUCCESS;
}