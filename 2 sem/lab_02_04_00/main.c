# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

# define EXIT_LEN_MORE_THAN_MYMAX 100
# define EXIT_INVALID_LEN 4

# define NMAX 1024
# define MYMAX 10

int input(int arr[], size_t *p)
{
	size_t i = 0;
	int eof_error;

	while (i < MYMAX && (eof_error = scanf("%d", arr + i)) != 0 && eof_error != EOF)
	{
		i++;
	}
	*p = i;

	if (i == MYMAX && scanf("%d", &eof_error) != 0)
		return EXIT_LEN_MORE_THAN_MYMAX;

	if (i == 0)
		return EXIT_INVALID_LEN;
	return EXIT_SUCCESS;
}

int bubblesort(int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
		for (size_t j = 0; j < len - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}	
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
	size_t *p = &len;

	int input_error;
	
	input_error = input(a, p);

	if (input_error == EXIT_INVALID_LEN)
		return EXIT_INVALID_LEN;

	bubblesort(a, len);
	output(a, len);

	if (input_error == EXIT_LEN_MORE_THAN_MYMAX)
		return EXIT_LEN_MORE_THAN_MYMAX;
	
	return EXIT_SUCCESS;
}