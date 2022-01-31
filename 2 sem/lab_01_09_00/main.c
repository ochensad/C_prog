# include <stdio.h>
# include <stdlib.h>
# include <math.h>

double division(double x, double i)
{
	return (x / i);
}

int main(void)
{
	double x;
	double g = 0.0;
	double i = 1.0;
	
	if (scanf("%lf", &x) != 1 || x < 0)
		return EXIT_FAILURE;
	
	while (x >= 0)
	{
		g += division(x, i);
		i += 1.0;
		if (scanf("%lf", &x) != 1)
			return EXIT_FAILURE;
	}
	
	g = sqrt(g);
	
	printf("%.6lf", g);
	return EXIT_SUCCESS;
}