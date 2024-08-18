#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define MAX_NUMBER 1000000
#define NUMBERS 30000000

typedef struct
{
    size_t number;
    size_t occurance;
} results;

void array_populator(size_t* array, size_t size)
{
    srand((unsigned int)time(NULL));
    while(size)
        array[--size] = (size_t) (rand() % MAX_NUMBER);
}

void array_printer(size_t array_size, size_t* array)
{
    while(array_size)
        printf("%zu\n", array[--array_size]);
}

results* mode(size_t* array, size_t array_size)
{
    size_t iter;
    size_t occurance_count[MAX_NUMBER] = {0};
    results* retour;
    
    retour = calloc(1, sizeof(results));
    retour->number = 0;
    retour->occurance = 0;  
    if(!retour)
        return (NULL);

    iter = 0;
    if(NUMBERS < MAX_NUMBER)
    {
        puts("Using method A");
        while(iter < array_size)
        {
            occurance_count[array[iter]]++;
            if(occurance_count[array[iter]] > retour->occurance)
            {
                retour->number = array[iter];
                retour->occurance = occurance_count[array[iter]];    
            }
            iter++;
        }
    }
    else
    {
        puts("Using method B");
        while(iter < array_size)
        {
            occurance_count[array[iter]]++;
            iter++;
        }
        iter = 0;
        while(iter < MAX_NUMBER)
        {
            if(occurance_count[iter] > retour->occurance)
            {
                retour->number = iter;
                retour->occurance = occurance_count[iter];    
            }
            iter++;
        }  

    }
    return (retour);
}

int	main(void)
{
    size_t* dynamic_array = calloc(NUMBERS, sizeof(size_t));
    results* result;
    
    array_populator(dynamic_array, NUMBERS);
    int times = 100;
    while(times)
    {
        result = mode(dynamic_array, NUMBERS);
        if(!result)
            puts("Calculations failed!");
        times--;
        free(result);
    }
    result = mode(dynamic_array, NUMBERS);
    printf
    (
        "Most popular number is %lu, occuring %lu times.\n",
        result->number, result->occurance
    );

    return (0);   
}
