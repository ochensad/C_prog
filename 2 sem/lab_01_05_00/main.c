#include <stdio.h>
#include <stdlib.h>

int power(int a, int n)
{
	int expon = 1;
	while (n > 0)
	{
		expon *= a;
		n--;
	}
	return expon;
}
int main(void)
{
	int a, n;
	int answer;
	
	if (scanf("%d", &a) != 1)
		return EXIT_FAILURE;
	if (scanf("%d", &n) != 1 || n <= 0)
		return EXIT_FAILURE;
	
	answer = power(a, n);
	printf("%d", answer);
	return EXIT_SUCCESS;
}