# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <sys/time.h>

# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4

# define NMAX 10024
# define MYMAX 10

int input(int a[], size_t len)
{
	for (size_t j = 0; j < len; j++)
	{
		if (scanf("%d", &a[j]) != 1)
		{
			return EXIT_INVALID_NUMBERS;
		}
	}
	return EXIT_SUCCESS;
}

int process_3(int *pstart, int *pend)
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
	return EXIT_SUCCESS;
}

int main(void)
{
	int a[NMAX];
	size_t len = 0;


	if (scanf("%zu", &len) != 1 || len <= 0)
		return EXIT_INVALID_LEN;
	
	struct timeval tm_start, tm_end;
	int elapsed_time = 0;
	input(a, len);
	int b[NMAX];
	size_t len_b = len;

	for (size_t i = 0; i < len; i++)
	{
		b[i] = a[i];
	}
	gettimeofday(&tm_start, NULL);
	process_3(b, b + len_b);
	gettimeofday(&tm_end, NULL);

	elapsed_time += ((tm_end.tv_sec - tm_start.tv_sec) * 1000000LL + (tm_end.tv_usec - tm_start.tv_usec));

	printf("%d ", elapsed_time);
	return EXIT_SUCCESS;
}