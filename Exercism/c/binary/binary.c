#include "binary.h"

int convert(const char *input)
{
    int result = 0;
    int len = 0;

    while(input[len])
    {
        if (input[len] != '1' && input[len] != '0')
            return -1;
        result <<= 1;
        result += (input[len] - 48);
        len++;
    }
    return result;
}