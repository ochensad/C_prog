# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define C1 4.0
# define C2 2.0

int main(void)
{
	double a, b;
	double h;
	double x;
	double p;
	
	scanf("%lf%lf", &a, &b);
	scanf("%lf", &h);
	
	x = sqrt((h * h) + (b - a) * (b - a) / C1);
	p = a + b + C2 * x;
	
	printf("%.6lf", p);
	return EXIT_SUCCESS;
}	