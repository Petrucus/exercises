#include <stdio.h>
#include <stdlib.h>
#define LINE_SIZE (rows * 2 + 1)

void	pascalian_triangle(int rows)
{
	int	**table;
	int	*line;
	int	iter;
	int	center;
	int	local_rows;
	int	populate;

	local_rows = 1;
	center = rows - 1;
	table = calloc(rows, sizeof(int *));
	line = calloc((LINE_SIZE), sizeof(int));
	if (!line && !table)
		exit(1);
	line[center] = 1;
	table[0] = line;
	iter = 1;
	while (local_rows < rows)
	{
		line = calloc((LINE_SIZE), sizeof(int));
		if (!line)
			exit(1);
		line[center - iter] = 1;
		line[center + iter] = 1;
		populate = 0;
		while (populate < LINE_SIZE)
		{
			line[populate] = table[local_rows - 1][populate - 1]
				+ table[local_rows - 1][populate + 1];
			populate++;
		}
		table[iter] = line;
		iter++;
		local_rows++;
	}
	local_rows = 0;
	while (local_rows < rows)
	{
		iter = 0;
		while (iter < (rows * 2) - 1)
		{
			if (table[local_rows][iter] == 0)
			{
				printf("\t");
				iter++;
				continue ;
			}
			else
				printf("%4d", table[local_rows][iter]);
			iter++;
		}
		printf("\n");
		local_rows++;
	}
}

int	main(void)
{
	pascalian_triangle(15);
}