/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:47:25 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 13:06:14 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

struct	s_square;

typedef struct s_square
{
	int				x;
	int				y;
	int				size;
	int				initial_size;
	struct s_square	*prev;
	struct s_square	*next;
}	t_square;

typedef struct s_map
{
	int			nbr_line;
	char		empty;
	char		wall;
	char		full;
	int			line_size;

	t_square	*first;
	int			x_max;
	int			y_max;
	int			size_max;
}	t_map;

t_map		*init_map(void);
int			add_first_if_null(t_map *map);
void		free_map(t_map *map);

t_square	*create_square(int x, int y, int size);
t_square	*add_square_next_to(t_square *new, t_map *map, t_square *prev);
t_square	*get_last_square(t_map *map);
void		delete_square(t_map *map, t_square *square);

#endif
