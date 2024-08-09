#include <stdio.h>

void floyds_triangle()
{
    int position;
    int iter;
    int increment;

    position = 1;
    increment = 1;
    while(increment < 5)
    {
        iter = increment++;
        while(iter--)
        {
            printf("%d", position++);
        }
        printf("\n");
    }
}

int main()
{
    floyds_triangle();
}