#include <float.h>
#include <stdio.h>
#include <stdlib.h>

double	sq_root(double x)
{
	double	low;
	double	high;
	double	mid;
	double	delta;

	low = 0;
	high = x / 2;
	delta = 0.000000001f;
	while (high - low > delta)
	{
		mid = (low + high) / 2;
		if ((mid * mid) < x)
			low = mid;
		else
			high = mid;
	}
	return (mid);
}

int	main(int argc, char **argv)
{
	double	input;
	double	result;

	if (argc != 2)
	{
		puts("Need an integer to provide its square root!");
		return (1);
	}
	input = strtod(argv[1], NULL);
	result = sq_root(input);
	printf("%.11f\n", sq_root(input));
	printf("%f\n", result * result);
	return (0);
}
