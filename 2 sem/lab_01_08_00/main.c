# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <inttypes.h>
# include <limits.h>

# define MAX_EXP 2147483648

void print_bin(uint32_t bin_a, uint32_t max_exp)
{		
	for (int i = 1; i <= (int)(CHAR_BIT * sizeof(uint32_t)); i++)
	{
		if (bin_a >= max_exp)
		{
			printf("1");
			bin_a -= max_exp;
		}
		else
			printf("0");
		max_exp /= 2;
	}
}
int main(void)
{
	uint32_t a;
	int n;
	uint32_t bin_a;
	uint32_t max_exp = MAX_EXP;
	
	if (scanf("%"SCNu32, &a) != 1)
	{
		printf("Error: invalid integer");
		return EXIT_FAILURE;
	}
	if (scanf("%d", &n) != 1 || n < 0)
	{
		printf("Error: invalid integer");
		return EXIT_FAILURE;
	}
	
	bin_a = (a << ((int)(CHAR_BIT * sizeof(uint32_t)) - n)) | (a >> n);
	
	printf("Result: ");
	print_bin(bin_a, max_exp);
	return EXIT_SUCCESS;
}
	