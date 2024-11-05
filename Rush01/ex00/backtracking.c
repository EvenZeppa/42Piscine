#include "ftlib.h"

int	has_no_multiple_int(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && array[i] == array[j] && array[i] != 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	sup_to(int *array, int i, int *visible, int *pov)
{
	if (array[i] > *visible)
	{
		*visible = array[i];
		(*pov)--;
	}
}

int	check(int *array, int pov_l, int pov_r, int size)
{
	int	visible_l;
	int	visible_r;
	int	i;
	int	has_zero;

	visible_l = 0;
	visible_r = 0;
	i = 0;
	has_zero = 0;
	while (i < size)
	{
		sup_to(array, i, &visible_l, &pov_l);
		sup_to(array, (size - i - 1), &visible_r, &pov_r);
		if (array[i] == 0)
			has_zero = 1;
		i++;
	}
	if (!has_no_multiple_int(array, size) || (pov_r < -10 || pov_l < -10)
		|| ((pov_r != 0 || pov_l != 0) && has_zero == 0))
		return (0);
	return (1);
}

int	next_pos(int ***tab, int **povs, int coord[2], int config[2])
{
	int	*col;
	int	*row;
	int	is_ended;

	malloc_all(&col, &row, config[1]);
	is_ended = 0;
	while (config[0] <= config[1])
	{
		(*tab)[coord[0]][coord[1]] = config[0];
		get_col((*tab), &col, coord[1], config[1]);
		get_row((*tab), &row, coord[0], config[1]);
		if (
			check(col, get_pov_colup(povs, coord[1])
				, get_pov_coldown(povs, coord[1]), config[1])
			&& check(row, get_pov_rowleft(povs, coord[0])
				, get_pov_rowright(povs, coord[0]), config[1]))
			if (cond((int [4]){coord[0], coord[1], config[0], config[1]}
				, &is_ended, tab, povs) == 0)
				return (free(col), free(row), 1);
		if (is_ended == 1)
			return (free(col), free(row), 1);
		config[0]++;
	}
	(*tab)[coord[0]][coord[1]] = 0;
	return (free(col), free(row), 0);
}

// int	next_pos(int ***tab, int **povs, int coord[2], int config[2])
// {
// 	int	*col;
// 	int	*row;
// 	int	is_ended;

// 	col = malloc(sizeof(int) * config[1]);
// 	row = malloc(sizeof(int) * config[1]);
// 	is_ended = 0;
// 	while (config[0] <= config[1])
// 	{
// 		(*tab)[coord[0]][coord[1]] = config[0];
// 		get_col((*tab), &col, coord[1], config[1]);
// 		get_row((*tab), &row, coord[0], config[1]);
// 		if (
// 			check(col, get_pov_colup(povs, coord[1])
// 				, get_pov_coldown(povs, coord[1]), config[1])
// 			&& check(row, get_pov_rowleft(povs, coord[0])
// 				, get_pov_rowright(povs, coord[0]), config[1]))
// 		{
// 			if (coord[1] == config[1] - 1 && coord[0] == config[1] - 1)
// 				return (free(col), free(row), 1);
// 			if (coord[1] == config[1] - 1)
// 				is_ended = next_pos(tab, povs,
// 						(int [2]){coord[0] + 1, 0}, (int [2]){1, config[1]});
// 			else
// 				is_ended = next_pos(tab, povs, (int [2])
// 					{coord[0], coord[1] + 1}, (int [2]){1, config[1]});
// 		}
// 		if (is_ended == 1)
// 			return (free(col), free(row), 1);
// 		config[0]++;
// 	}
// 	(*tab)[coord[0]][coord[1]] = 0;
// 	return (free(col), free(row), 0);
// }
