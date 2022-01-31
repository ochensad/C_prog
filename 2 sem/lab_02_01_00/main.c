# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

# define EXIT_NOT_ENOUGH_NUMBERS 2
# define EXIT_INVALID_NUMBERS 3
# define EXIT_INVALID_LEN 4
# define EXIT_NO_EVEN 5

# define NMAX 1024
# define MYMAX 10

int input(int arr[], size_t len)
{
	int eof_test;
	for (size_t i = 0; i < len; i++)
	{
		if ((eof_test = scanf("%d", arr + i)) != 1)
		{
			if (eof_test == EOF)
				return EXIT_NOT_ENOUGH_NUMBERS;
			return EXIT_INVALID_NUMBERS;
		}
	}
	return EXIT_SUCCESS;
}

int sum_evens(int arr[], size_t len)
{
	int sum_of_even = 0;
	int flag = 0;
	for (size_t i = 0; i < len; i++)
		if (arr[i] % 2 == 0)
		{
			sum_of_even += arr[i];
			flag = 1;
		}
	
	if (flag == 0)
		sum_of_even = -1;
	
	return sum_of_even;
}

int main(void)
{
	int a[NMAX];
	size_t len = 0;
	int sum_nm;
	int input_error;

	if (scanf("%zu", &len) != 1 || len <= 0 || len > MYMAX)
		return EXIT_INVALID_LEN;
	
	input_error = input(a, len);
	if (input_error == EXIT_INVALID_NUMBERS)
		return EXIT_INVALID_NUMBERS;
	else if (input_error == EXIT_NOT_ENOUGH_NUMBERS)
		return EXIT_NOT_ENOUGH_NUMBERS;

	sum_nm = sum_evens(a, len);

	if (sum_nm == -1)
		return EXIT_NO_EVEN;
	printf("Sum of even numbers = %d", sum_nm);
	return EXIT_SUCCESS;
}	