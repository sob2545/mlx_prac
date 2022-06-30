#include "stdio.h"
#include "math.h"

int	main(void)
{
	double a = 0.73;
	double b = sqrt(1 - pow(a, 2));

	printf("%f, %f\n", a, b);
}
