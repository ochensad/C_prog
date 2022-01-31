# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

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
int process_01(int arr[NMAX][NMAX], size_t n, size_t m, int dst[NMAX])
{
	for (size_t i = 0; i < n; i++)
	{
		int flag = 1;
		for (size_t j = 0; j < (m / 2); j++)
			if (arr[i][j] != arr[i][m - j - 1])
				flag = 0;
		if (flag == 1)
			dst[i] = 1;
		else
			dst[i] = 0;
	}
	return EXIT_SUCCESS;
}
int output(int arr[NMAX], size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return EXIT_SUCCESS;
}
int main(void)
{
	int a[NMAX][NMAX];
	size_t n;
	size_t m;
	int b[NMAX];
	
	if (scanf("%zu", &n) != 1 || n <= 0 || n > MYMAX)
		return EXIT_INVALID_LEN;
	if (scanf("%zu", &m) != 1 || m <= 0 || m > MYMAX)
		return EXIT_INVALID_LEN;
	
	int input_error;
	input_error = input(a, n, m);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	process_01(a, n, m, b);

	output(b, n);
	return EXIT_SUCCESS;
}