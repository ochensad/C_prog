# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

# define EXIT_LEN_MORE_THAN_MYMAX 100
# define EXIT_INVALID_LEN 4

# define NMAX 200000
# define MYMAX 10

# define SWAP(A,B) { int t = A; A = B; B = t;}

size_t input(int arr[])
{
	size_t i = 0;
	int eof_error;
	while ((eof_error = scanf("%d", arr + i)) != 0 && eof_error != EOF)
	{
		i++;
	}

	return i;
}

int bubblesort(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		for (size_t j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
				SWAP(arr[j],arr[j + 1]);
				
	return EXIT_SUCCESS;
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

	int flag = 0;
	
	len = input(a);

	if (len == 0)
		return EXIT_INVALID_LEN;

	bubblesort(a, len);
	output(a, len);
	
	return EXIT_SUCCESS;
}