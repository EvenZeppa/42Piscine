/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_engine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:51:06 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 20:41:48 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_ENGINE_H
# define SQUARE_ENGINE_H

# include "map.h"

int	range_lookup(t_square *square, int *x, int *range);
int	square_divider(t_map *map, t_square *square, int x, int y, int range);
int	*square_engine(t_map *map, int **range, int **range_mask, int y);

#endif
