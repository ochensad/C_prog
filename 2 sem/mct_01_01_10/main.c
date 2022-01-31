# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define PHI 1e-10
double s(double x, double eps)
{
	double i = 2.0;
	double si = (x * x * x) / -3;
	double s_num = 0;
	while (fabs(si) > eps)
	{
		si *= (-1.0) * (x * x) * (1.0 + i) / (i * i + 2.0 * i);
		s_num +=si;
		i++;
	}
	return s_num;
}
double f(double x)
{
	double fx = 0;
	fx = (1.0/(x * x * x)) * (1.0 - exp(-x * x) * (1.0 + x * x));
	return fx;
}
int main(void)
{
	double x;
	double eps;
	double s_num;
	double f_num;
	
	if (scanf("%lf", &x) != 1 || fabs(x) < PHI)
		return EXIT_FAILURE;
	if (scanf("%lf", &eps) != 1 || eps <= 0 || eps >= 1)
		return EXIT_FAILURE;
	
	f_num = f(x);
	s_num = s(x, eps);

	printf("%e\n", f_num);
	printf("%g", s_num);
	
	return EXIT_SUCCESS;
}