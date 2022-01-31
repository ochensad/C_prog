# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

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

double average(int arr[], size_t len)
{
	double sum_of_numbers = 0.0;

	for (size_t i = 0; i < len ; i++)
		sum_of_numbers += arr[i];

	return (sum_of_numbers / len);
}

size_t copy_greater(int src[], size_t len_src, int dst[], double g)
{
	size_t len_dst = 0;

	for (size_t i = 0; i < len_src; i++)
		if (src[i] > g)
		{
			len_dst++;
			dst[len_dst - 1] = src[i];
		}
	return len_dst;
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
	size_t len_a = 0;

	int b[NMAX];
	double arth_mn = 0.0;
	int input_error;

	if (scanf("%zu", &len_a) != 1 || len_a <= 0 || len_a > MYMAX)
		return EXIT_INVALID_LEN;
	
	input_error = input(a, len_a);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	else if (input_error == EXIT_NOT_ENOUGH_NUMBERS)
		return EXIT_NOT_ENOUGH_NUMBERS;

	arth_mn = average(a, len_a);
	size_t len_b = copy_greater(a, len_a, b, arth_mn);

	if (len_b == 0)
		return EXIT_INVALID_LEN;
 
	output(b, len_b);
	return EXIT_SUCCESS;
}