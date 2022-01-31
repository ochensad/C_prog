# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <math.h>

# define EXIT_NOT_ENOUGH_NUMBERS 2
# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 256
# define MYMAX 10
# define SUM 10
int input(int arr[NMAX][NMAX], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			if (scanf("%d", &arr[i][j]) != 1)
				return EXIT_INVALID_NUMBERS;
	return EXIT_SUCCESS;
}
int find_more_than_ten(int arr[NMAX][NMAX], size_t n, size_t m, int b[NMAX], size_t *len_b)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			int num = abs(arr[i][j]);
			int sum_n = 0;
			while ((sum_n <= SUM) && (num > 0))
			{
				sum_n += (num % 10);
				num /= 10;
			}
			
			if (sum_n > SUM)
			{
				b[*len_b] = arr[i][j];
				*len_b += 1;
			}
		}
	
	if (*len_b == 0)
		return EXIT_INVALID_LEN;
	return EXIT_SUCCESS;
}

int circular_shift(int b[NMAX], size_t len_b)
{
	for (size_t k = 0; k < 3; k++)
	{
		int t = b[0];
		for (size_t i = 0; i < len_b - 1; i++)
			b[i] = b[i + 1];
		b[len_b - 1] = t;
	}
	return EXIT_SUCCESS;
}

int shift_numbers(int arr[NMAX][NMAX], size_t n, size_t m)
{
	int b[NMAX];
	size_t len_b = 0;

	int find_error;
	find_error = find_more_than_ten(arr, n, m, b, &len_b);
	if (find_error == EXIT_INVALID_LEN)
		return EXIT_INVALID_LEN;
	
	circular_shift(b, len_b);

	size_t count = 0;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			int num = abs(arr[i][j]);
			int sum_n = 0;
			while ((sum_n <= SUM) && (num > 0))
			{
				sum_n += (num % 10);
				num /= 10;
			}
			
			if (sum_n > SUM)
			{
				arr[i][j] = b[count];
				count++;
			}
		}
	return EXIT_SUCCESS;
}
int output(int arr[NMAX][NMAX], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return EXIT_SUCCESS;
}
int main(void)
{
	int a[NMAX][NMAX];
	size_t n;
	size_t m;
	
	if (scanf("%zu", &n) != 1 || n <= 0 || n > MYMAX)
		return EXIT_INVALID_LEN;
	if (scanf("%zu", &m) != 1 || m <= 0 || m > MYMAX)
		return EXIT_INVALID_LEN;
	
	int input_error;
	input_error = input(a, n, m);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	
	int shift_error;
	shift_error = shift_numbers(a, n, m);
	if (shift_error == EXIT_INVALID_LEN)
		return EXIT_INVALID_LEN;
	
	output(a, n, m);
	return EXIT_SUCCESS;
}