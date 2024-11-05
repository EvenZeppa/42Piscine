#include "ftlib.h"

int	main(int argc, char *argv[])
{
	int		**povs;
	int		**tab;
	int		size;

	if (argc == 2)
	{
		size = parse_pov(&povs, argv[1]);
		if (size == -1 || build_tab_tab(&tab, size, size))
		{
			error();
			return (1);
		}
		if (!next_pos(&tab, povs, (int [2]){0, 0}, (int [2]){1, size}))
		{
			error();
		}
		else
			draw_tab_tab(tab, size, size);
		free_tab_tab(povs, 4);
		free_tab_tab(tab, size);
		return (0);
	}
	error();
	return (1);
}
