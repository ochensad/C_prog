#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sx_series(double x, double epsilon)
{
	double sx = 0.0, si = 1.0;
	double i = 0.0;
	while (fabs(si) >= epsilon)
	{
		i += 1.0;
		sx += si;
		si = si * (x / i);
	}
	return sx;
}
int main(void)
{
	double x, epsilon;
	double sx, fx;
	double absolute_error, relative_error;
	
	if (scanf("%lf", &x) != 1)
		return EXIT_FAILURE;
	if (scanf("%lf", &epsilon) != 1 || epsilon <= 0 || epsilon > 1)
		return EXIT_FAILURE;
	
	sx = sx_series(x, epsilon);
	fx = exp(x);
	absolute_error = fabs(fx - sx);
	relative_error = absolute_error / fabs(fx);
	
	printf("S(x) = %.6lf\n", sx);
	printf("F(x) = %.6lf\n", fx);
	printf("AbsoluteError = %.6lf\n", absolute_error);
	printf("RelativeError = %.6lf\n", relative_error);
	return EXIT_SUCCESS;
}