# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

# define EXIT_NOT_ENOUGH_NUMBERS 2
# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 1024
# define MYMAX 10

int input(int *pstart, int *pend)
{
	int eof_test;
	while (pstart < pend)
	{
		if ((eof_test = scanf("%d", pstart)) != 1)
		{
			if (eof_test == EOF)
				return EXIT_NOT_ENOUGH_NUMBERS;
			return EXIT_INVALID_NUMBERS;
		}
		pstart++;
	}
	return EXIT_SUCCESS;
}

int g(int *pstart, int *pend)
{
	int max = *pstart + *(pend - 1);
	
	while (pstart < pend)
	{
		int k = *pstart + *(pend - 1);
		if (k > max)
			max = k;
		pstart++;
		pend--;
	}
	return max;
}

int main(void)
{
	int a[NMAX];
	size_t len = 0;

	int input_error;
	
	int max = 0;

	if (scanf("%zu", &len) != 1 || len <= 0 || len > MYMAX)
		return EXIT_INVALID_LEN;
	
	input_error = input(a, a + len);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	else if (input_error == EXIT_NOT_ENOUGH_NUMBERS)
		return EXIT_NOT_ENOUGH_NUMBERS;
	max = g(a, a + len);
	
	printf("%d", max);
	return EXIT_SUCCESS;
}