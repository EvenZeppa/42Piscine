#ifndef FTLIB_H
# define FTLIB_H
# include <stdlib.h>
# include <unistd.h>

int		parse_pov(int ***povs, char *str);
int		build_tab_tab(int ***tab, int out_size, int in_size);
int		next_pos(int ***tab, int **povs, int coord[2], int config[2]);
void	draw_tab_tab(int **tab, int out_size, int in_size);
void	error(void);
void	free_tab_tab(int **tab, int out_size);
void	get_col(int **tab, int **col, int y, int size);
void	get_row(int **tab, int **row, int x, int size);
int		check(int *array, int pov_l, int pov_r, int size);
int		get_pov_colup(int **povs, int y);
int		get_pov_coldown(int **povs, int y);
int		get_pov_rowleft(int **povs, int x);
int		get_pov_rowright(int **povs, int x);
int		nb_int(char *str);
void	free_col_row(int **col, int **row);
int		cond(int all[4], int *is_ended, int ***tab, int **povs);
void	malloc_all(int **col, int **row, int size);
#endif
