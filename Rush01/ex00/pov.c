#include "ftlib.h"

int	parse_pov(int ***povs, char *str)
{
	int	count;
	int	size;
	int	is_space;
	int	i;

	is_space = 1;
	i = 0;
	count = nb_int(str);
	size = count / 4;
	if (count % 4 != 0 || build_tab_tab(povs, 4, size) == -1)
		return (-1);
	i = 0;
	count = 0;
	while (i < 4)
	{
		count = 0;
		while (count < size)
		{
			(*povs)[i][count++] = *str - '0';
			str += 2;
		}
		i++;
	}
	return (size);
}

int	get_pov_colup(int **povs, int y)
{
	return (povs[0][y]);
}

int	get_pov_coldown(int **povs, int y)
{
	return (povs[1][y]);
}

int	get_pov_rowleft(int **povs, int x)
{
	return (povs[2][x]);
}

int	get_pov_rowright(int **povs, int x)
{
	return (povs[3][x]);
}
