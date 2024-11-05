/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:51:54 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 21:16:26 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "map.h"

void	square_build(t_map *map, int *range, int *range_mask, int y);
int		malloc_ranges(char *buffer, int **range, int **range_mask);
int		range_gen(char **buffer, t_map *map, int **range, int **range_mask);
int		solve(t_map *map, char *buffer, int size_buffer);

#endif
