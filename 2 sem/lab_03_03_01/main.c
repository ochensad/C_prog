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
int max_row(int arr[NMAX], size_t len)
{
	int max_i = arr[0];
	for (size_t i = 0; i < len; i++)
		if (arr[i] > max_i)
			max_i = arr[i];
	return max_i;
}
int bubble_sort(int arr[NMAX][NMAX], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n - i - 1; j++)
			if (max_row(arr[j + 1], m) > max_row(arr[j], m))
				for (size_t k = 0; k < m; k++)
				{
					int t = arr[j + 1][k];
					arr[j + 1][k] = arr[j][k];
					arr[j][k] = t;
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
	bubble_sort(a, n, m);
	output(a, n, m);
	return EXIT_SUCCESS;
}