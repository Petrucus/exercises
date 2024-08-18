#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 20

void	array_populator(size_t array_size, size_t *array)
{
	size_t	*end;

	end = array + array_size;
	srand((unsigned int)time(NULL));
	while (array < end)
		*array++ = (size_t)(rand() % MAX_NUMBER);
}

void	array_printer(size_t array_size, size_t *array, int ascending)
{
	size_t	*end;

	puts("=== Array ===");
	if (!ascending)
		while (array_size)
			printf("%zu\n", array[--array_size]);
	else
	{
		end = array + array_size;
		while (array < end)
			printf("%zu\n", *array++);
	}
}

void	swap(size_t *a, size_t *b)
{
	size_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	array_sorter(size_t array_size, size_t *array)
{
	size_t	loop;
	size_t	inner_loop;

	loop = 0;
	while (loop < array_size - 1)
	{
		inner_loop = loop + 1;
		while (inner_loop < array_size)
		{
			if (array[loop] > array[inner_loop])
				swap(&array[loop], &array[inner_loop]);
			inner_loop++;
		}
		loop++;
	}
}

size_t	median(size_t array_size, size_t *array)
{
	// Should _this_ function check if array sorted ?
	if (array_size % 2)
		return (array[array_size / 2]);
	else
		return ((array[array_size / 2] + array[array_size / 2 - 1]) / 2);
}

int	main(void)
{
	size_t	numbers;
	size_t	*dynamic_array;

	numbers = 14;
	dynamic_array = calloc(numbers, sizeof(size_t));
	if (!dynamic_array)
		return (1);
	array_populator(numbers, dynamic_array);
	array_printer(numbers, dynamic_array, 1);
	array_sorter(numbers, dynamic_array);
	array_printer(numbers, dynamic_array, 1);
	printf("Median is:%lu\n", median(numbers, dynamic_array));
	free(dynamic_array);
	return (0);
}
