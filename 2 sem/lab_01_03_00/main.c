# include <stdio.h>
# include <stdlib.h>

# define C1 240.0
# define C2 10000.0

int main(void)
{
	double h, t;
	double m;
	double bmi;
	double mnormal;
	
	scanf("%lf%lf", &h, &t);
	scanf("%lf", &m);
	
	mnormal = (h * t / C1);
	bmi = (m * C2 / (h * h));
	
	printf("mnormal: %.6lf\n", mnormal);
	printf("BMI: %.6lf", bmi);
	return EXIT_SUCCESS;
}