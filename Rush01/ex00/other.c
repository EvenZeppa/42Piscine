#include "ftlib.h"

void	draw_tab_tab(int **tab, int out_size, int in_size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < out_size)
	{
		j = 0;
		while (j < in_size)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j != in_size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_col(int **tab, int **col, int y, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		(*col)[i] = tab[i][y];
}

void	get_row(int **tab, int **row, int x, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		(*row)[i] = tab[x][i];
}

void	error(void)
{
	write(1, "Error\n", 6);
}

int	nb_int(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && str[i] >= '0' && str[i] <= '9')
			count++;
		else if ((i % 2 == 1 && str[i] != ' ') || str[i - 1] == ' ')
			return (-1);
		i++;
	}
	return (count);
}
