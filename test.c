#include "stdio.h"
#include "math.h"

int	main(void)
{
	double a = 0.73;
	double b = sqrt(1 - pow(a, 2));
	double c = sqrt(pow(-0.13, 2) + pow(0.33, 2) + pow(0.43, 2) + pow(0.83, 2));
	printf("%f\n", (a + 1));

	printf("%f, %f, %f\n", a, b, c);
}
