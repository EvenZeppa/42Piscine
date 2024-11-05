/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:01:27 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 13:29:35 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "validation.h"
# include "solver.h"
# include "parser.h"
# include "map.h"
# include "print.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

t_square	**init_squares_tab(int size);
void		print_map_with_squares(
				t_map *map, t_square **squares, char *buffer, int size_buffer);
void		print_map_struct(t_map *map);
t_square	*get_square_by_x_y(t_map *map, int x, int y);

#endif
