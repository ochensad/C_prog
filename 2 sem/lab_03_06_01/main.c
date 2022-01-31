# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

# define EXIT_NOT_ENOUGH_NUMBERS 2
# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 256
# define MYMAX 10

int spiral_filling(int arr[NMAX][NMAX], size_t n, size_t m)
{
	size_t up_j = m;
	size_t up_i = n;
	size_t down_j = 0;
	size_t down_i = 0;
	int num = 1;
	size_t st_num = 1;
	
	if (m == 1 && n == 1)
	{
		arr[0][0] = 1;
		return EXIT_SUCCESS;
	}
	
	while (st_num <= (m * n))
	{
		for (size_t j = down_j; j < up_j; j++)
		{
			arr[down_i][j] = num;
			num ++;
			st_num++;
		}
		for (size_t i = down_i + 1; i < up_i; i++)
		{
			arr[i][up_j - 1] = num;
			num ++;
			st_num++;
		}
		for (size_t j = up_j - 1; j > down_j; --j)
		{
			arr[up_i - 1][j - 1] = num;
			num++;
			st_num++;
		}
		for (size_t i = up_i - 2 ; i > down_i; --i)
		{
			arr[i][down_j] = num;
			num++;
			st_num++;
		}
		down_j++;
		down_i++;
		up_j--;
		up_i--;
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
	spiral_filling(a, n, m);
	output(a, n, m);
	return EXIT_SUCCESS;
}