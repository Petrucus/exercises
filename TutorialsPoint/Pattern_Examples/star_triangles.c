#include <stdlib.h>
#include <unistd.h>

int	str_len(char *e)
{
	int	len;

	len = 0;
	while (e[len])
		len++;
	return (len);
}

void	triangle_print(int n, int type, int action)
{
	char	*buffer[n];
	char	*line;
	int		iter;
	int		row;
	char	space;
	char	star;
	char	nuline;
	int		count;
	int		t_type;

	space = ' ';
	star = '*';
	nuline = '\n';
	count = 0;
	row = 0;
	if (n < 2)
	{
		write(1, "A triangle needs at least 2 rows!", 33);
		return ;
	}
	t_type = 0;
	switch (type)
	{
	case 1:
		t_type = 1;
		break ;
	case 2:
		t_type = 2;
		break ;
	case 3:
		t_type = 3;
		break ;
	}
	iter = 0;
	line = malloc((sizeof(char) * 2 * n) + 1);
	while (iter <= n)
	{
		line[count] = space;
		iter++;
		count++;
	}
	line[count++] = star;
	line[count++] = nuline;
	line[count] = '\0';
	buffer[row++] = line;
	if (action == 1)
		write(1, buffer[row - 1], str_len(buffer[row - 1]) + 1);
	while (row < n)
	{
		count = 0;
		iter = n - row;
		line = malloc((sizeof(char) * 2 * n) + 1);
		while (iter > 0)
		{
			line[count++] = space;
			iter--;
		}
		line[count++] = star;
		while (iter < (t_type * row))
		{
			if (row == (n - 1))
				line[count++] = star;
			else
				line[count++] = space;
			iter++;
		}
		line[count++] = star;
		line[count++] = nuline;
		line[count] = '\0';
		buffer[row++] = line;
		if (action == 1)
			write(1, buffer[row - 1], str_len(buffer[row - 1]));
	}
	if (action == 2)
	{
		iter = 0;
		while (row > 0)
		{
			--row;
			while (buffer[row][iter] != '\0')
				write(1, &buffer[row][iter++], 1);
			iter = 0;
		}
	}
	else if (action == 3)
	{
		--row;
		while (row >= 0)
		{
			iter = 1;
			while (iter <= str_len(buffer[row]))
			{
				write(1, &buffer[row][str_len(buffer[row]) - iter], 1);
				iter++;
			}
			row--;
		}
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	triangle_print(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
}
