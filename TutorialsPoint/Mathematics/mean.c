#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 10

void	array_populator(size_t array_size, size_t *array)
{
	size_t	start;

	start = 0;
	srand((unsigned int)time(NULL));
	while (start < array_size)
		array[start++] = (size_t)(rand() % MAX_NUMBER);
}

void	swap(size_t *a, size_t *b)
{
	size_t	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	array_printer(size_t array_size, size_t *array, int ascending)
{
	size_t	start;

	puts("=== Array ===");
	if (!ascending)
		while (array_size)
			printf("%zu\n", array[--array_size]);
	else
	{
		start = 0;
		while (start < array_size)
			printf("%zu\n", array[start++]);
	}
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

float	mean(size_t array_size, size_t *array, size_t field, size_t position)
{
	unsigned long	total;
	unsigned long	size;
	size_t			start;
	size_t			end;

	total = 0;
	size = array_size;
	switch ((field > 0) + (position > 0))
	{
	case 0:
		while (array_size)
		{
			printf("number :%lu\n", array[array_size - 1]);
			total += array[--array_size];
			printf("new total:%lu\n", total);
		}
		break ;
	case 2:
		if ((long)(position - field) < 0)
			start = 0;
		else
			start = position - field;
		end = position + field;
		size = end - start + 1;
		while (start <= end)
			total += array[start++];
		break ;
	case 1:
		if (position > 0)
			while (array_size >= position)
				total += array[array_size--];
		else
		{
			start = array_size / 2 - field;
			if (start < 0)
			{
				puts("Error: Line 76, start cannot be less than 0.");
				exit(1);
			}
			start = array_size / 2 - field;
			end = array_size / 2 + field;
			while (start <= end)
				total += array[start++];
			size = field * 2 + 1;
		}
		break ;
	}
	return ((float)total / (float)size);
}

int	main(int argc, char **argv)
{
	size_t	*dynamic_array;
	size_t	position;
	size_t	field;
	size_t	numbers;

	field = 0;
	position = 0; // NUMBERS / 5; Setting the index at 20%
	numbers = 10;
	switch (argc)
	{
	case 1:
		break ;
	case 2:
		field = (size_t)strtol(argv[1], NULL, 10);
		break ;
	case 3:
		field = (size_t)strtol(argv[1], NULL, 10);
		position = (size_t)strtol(argv[2], NULL, 10);
		break ;
	case 4:
		field = (size_t)strtol(argv[1], NULL, 10);
		position = (size_t)strtol(argv[2], NULL, 10);
		numbers = (size_t)strtol(argv[3], NULL, 10);
		break ;
	}
	printf("numbers is %zu.\n", numbers);
	dynamic_array = calloc(numbers, sizeof(size_t));
	array_populator(numbers, dynamic_array);
	if (field || position)
		array_sorter(numbers, dynamic_array);
	array_printer(numbers, dynamic_array, 1);
	printf("Very mean is: %f\n", mean(numbers, dynamic_array, field, position));
	free(dynamic_array);
}
