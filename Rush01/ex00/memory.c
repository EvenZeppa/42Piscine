#include "ftlib.h"

int	build_tab_tab(int ***tab, int out_size, int in_size)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	(*tab) = malloc(sizeof(int *) * out_size);
	if (*tab == NULL)
		return (-1);
	count = 0;
	i = 0;
	while (count < out_size)
	{
		(*tab)[count] = malloc(sizeof(int) * in_size);
		if ((*tab)[count] == NULL)
			return (-1);
		j = 0;
		while (j < in_size)
			(*tab)[count][j++] = 0;
		count++;
	}
	return (0);
}

void	free_tab_tab(int **tab, int out_size)
{
	int	i;

	i = 0;
	while (i < out_size)
	{
		free(tab[i++]);
	}
	free(tab);
}
