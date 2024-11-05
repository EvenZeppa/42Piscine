/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:02:30 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 13:02:19 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/print.h"
#include <unistd.h>

/* Renvoie les coordonees lineaires sur des donnees 2D fournies */
int	coord_to_index(int x, int y, int line_size)
{
	return ((y * line_size) + x);
}

/* Affiche la map en y ajoutant le plus grand carre de celle-ci */
void	print_map(t_map *map, char *buffer, int size_buffer)
{
	int	x;
	int	y;

	y = map->y_max;
	while (y < (map->y_max + map->size_max))
	{
		x = map->x_max;
		while (x < (map->x_max + map->size_max))
		{
			buffer[coord_to_index(x, y, map->line_size + 1)] = map->full;
			x++;
		}
		y++;
	}
	write(1, buffer, size_buffer);
}
