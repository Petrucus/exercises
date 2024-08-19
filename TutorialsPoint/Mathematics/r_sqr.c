#include <stdlib.h>
#include <stdio.h>
#include <float.h>

double sq_root( double x ) {
    double low = 0;
    double high = x / 2;
    double mid;
    double delta;

    delta = 0.000000001f;
    while( high - low > delta)
    {
        mid = (low + high) / 2;
        if((mid*mid) < x)
            low = mid;
        else
            high = mid;
    }
    return (mid);
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        puts("Need an integer to provide its square root!");
        return 1;
    }
    double input = strtod(argv[1], NULL);
    double result = sq_root(input);
    printf("%.11f\n", sq_root(input));
    printf("%f\n",result * result);
    return 0;
}
