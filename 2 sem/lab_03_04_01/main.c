# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

# define EXIT_NOT_ENOUGH_NUMBERS 2
# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 256
# define MYMAX 10
int input(int arr[NMAX][NMAX], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			if (scanf("%d", &arr[i][j]) != 1)
				return EXIT_INVALID_NUMBERS;
	return EXIT_SUCCESS;
}
int change_place(int arr[NMAX][NMAX], size_t n, size_t m)
{
	for (size_t i = 0; i < (n / 2); i++)
		for (size_t j = i; j < (m - i); j++)
		{
			int t = arr[n - i - 1][j];
			arr[n - i - 1][j] = arr[i][j];
			arr[i][j] = t;
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
	if (n != m)
		return EXIT_INVALID_LEN;
	int input_error;
	input_error = input(a, n, m);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	change_place(a, n, m);
	output(a, n, m);
	return EXIT_SUCCESS;
}