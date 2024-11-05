/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:51:41 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/26 00:49:12 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/square_engine.h"
#include <stdio.h>

int	range_lookup(t_square *square, int *x, int *range)
{
	int	i;

	i = 0;
	*x = 0;
	while (range[i] != -1 && *x < square->x + square->size)
	// while (range[i] != -1)
	{
		printf("range : %d\n", range[i]);
		printf("X : %d\n", *x);
		if (i % 2 == 1 && *x >= square->x && *x < square->x + square->size)
		{
			return (i);
		}
		*x += range[i++];
	}
	return (-1);
}

int	square_divider(t_map *map, t_square *square, int x, int y, int range)
{
	t_square	*child;
	int			child_size;
	(void) y;

	child_size = square->size - ((x - square->x) + range);
	if (child_size > map->size_max)
	{
		child = create_square(x + range, square->y, child_size);
		if (!child)
			return (0);
		add_square_next_to(child, 0, square);
		// printf("x : %d y : %d size; %d x donne : %d YYY %d\n", child->x, child->y, child->size, x, y);
		// if (y - square->y < x - square->x)
		// 	square->size = x - square->x;
		// else
		// 	square->size = y - square->y;
		square->size -= (child_size + range);
	}
	return (1);
}

int	*square_engine(t_map *map, int **range, int **range_mask, int y)
{
	t_square	*current;
	int			i;
	int			x;

	current = map->first;
	while (current->next)
	{
		i = range_lookup(current, &x, (*range));
		if (i != -1)
		{
			square_divider(map, current, x, y, (*range)[i]);
			(*range_mask)[i - 1] -= current->size;
			// (*range_mask)[i + 1] -= current->next->size;
		}
		if (current->size > map->size_max && (y - current->y) > current->size)
		{
			map->x_max = current->x;
			map->y_max = current->y;
			map->size_max = current->size;
		}
		// else
		// {

		// 	printf("YORN %d\n", current->size > map->size_max && (y - current->y) < current->size);

		// 	printf("C SIZE %d\n", current->size);
		// 	printf("C Y %d\n", y - current->y);
		// 	printf("MAP S %d\n", map->size_max);
		// }
		current = current->next;
		if (current->prev->size <= map->size_max)
			delete_square(map, current->prev);
	}
	return (*range_mask);
}
