#include "ftlib.h"

void	free_col_row(int **col, int **row)
{
	free(*col);
	free(*row);
}

int	cond(int all[4], int *is_ended, int ***tab, int **povs)
{
	if (all[1] == all[3] - 1 && all[0] == all[3] - 1)
		return (0);
	if (all[1] == all[3] - 1)
		*is_ended = next_pos(tab, povs,
				(int [2]){all[0] + 1, 0}, (int [2]){1, all[3]});
	else
		*is_ended = next_pos(tab, povs, (int [2])
			{all[0], all[1] + 1}, (int [2]){1, all[3]});
	return (1);
}

void	malloc_all(int **col, int **row, int size)
{
	*col = malloc(sizeof(int) * size);
	*row = malloc(sizeof(int) * size);
}
