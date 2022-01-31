# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <math.h>

# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 256
# define MYMAX 10
# define MAX_SUM_OF_NUMB_INT 90
int input(int arr[NMAX][NMAX], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
			if (scanf("%d", &arr[i][j]) != 1)
				return EXIT_INVALID_NUMBERS;
	return EXIT_SUCCESS;
}

int delite_el(int arr[NMAX][NMAX], size_t n, size_t m, int i_el, int j_el)
{
	for (size_t i = i_el + 1; i < n; i++)
		for (size_t j = 0; j < m; j++)
			arr[i - 1][j] = arr[i][j];
		
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = j_el + 1; j < m; j++)
			arr[i][j - 1] = arr[i][j];

	return EXIT_SUCCESS;
}

int find_min(int arr[NMAX][NMAX], size_t *n, size_t *m)
{
	int min_el = MAX_SUM_OF_NUMB_INT;
	int i_el = 0;
	int j_el = 0;
	
	for (size_t i = 0; i < *n; i++)
		for (size_t j = 0; j < *m; j++)
		{
			int num = abs(arr[i][j]);
			int sum = 0;
			while (num > 0)
			{
				sum += (num % 10);
				num /= 10;
			}
			
			if (sum < min_el)
			{
				min_el = sum;
				i_el = i;
				j_el = j;
			}
		}

	delite_el(arr, *n, *m, i_el, j_el);
	*n -= 1;
	*m -= 1;

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

	if (n == 1 || m == 1)
		return EXIT_INVALID_LEN;
	
	find_min(a, &n, &m);
	output(a, n, m);
	return EXIT_SUCCESS;
}