#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-10

double dot_product_in_vector_form(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double x12, x13, y12, y13;
	double dot_product_xy;
	
	x12 = x2 - x1;
	x13 = x3 - x1;
	y12 = y2 - y1;
	y13 = y3 - y1;
	
	dot_product_xy = x12 * x13 + y12 * y13;
	return dot_product_xy;
}

int main(void)
{
	double xa, ya;
	double xb, yb;
	double xc, yc;
	double scalar_a, scalar_b, scalar_c;
	int answer;
	
	if (scanf("%lf%lf", &xa, &ya) != 2)
		return EXIT_FAILURE;
	if (scanf("%lf%lf", &xb, &yb) != 2)
		return EXIT_FAILURE;
	if (scanf("%lf%lf", &xc, &yc) != 2)
		return EXIT_FAILURE;
	
	if (fabs((xc - xa) * (yb - ya) - (yc - ya) * (xb - xa)) < EPS)
		return EXIT_FAILURE;
	
	if (fabs(xa - xb + xc - xb) < EPS && fabs(ya - yc + yb - yc) < EPS)
		return EXIT_FAILURE;
	
	if ((fabs(xa - xb) < EPS && fabs(ya - yb) < EPS) || (fabs(xb - xc) < EPS && 
		fabs(yb - yc) < EPS) || (fabs(xc - xa) < EPS && fabs(yc - ya) < EPS))
		return EXIT_FAILURE;
		
	scalar_a = dot_product_in_vector_form(xa, ya, xb, yb, xc, yc);
	scalar_b = dot_product_in_vector_form(xb, yb, xa, ya, xc, yc);
	scalar_c = dot_product_in_vector_form(xc, yc, xa, ya, xb, yb);
	
	if ((fabs(scalar_a) < EPS) || (fabs(scalar_b) < EPS) || (fabs(scalar_c) < EPS))
		answer = 1;
	else
	{	
		if (scalar_a < EPS || scalar_b < EPS || scalar_c < EPS)
			answer = 2;
		else
			answer = 0;
	}
	printf("%d", answer);
	return EXIT_SUCCESS;
}