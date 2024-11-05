/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeel-qai <jeel-qai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:55:28 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 01:30:10 by jeel-qai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

/* FONCTIONS DANS MAIN() */
int	check_meta_data(t_map *map, char **buffer, int *read)
{
	int	nb;
	int	i;

	*read = 0;
	while ((*buffer)[*read] != '\n')
		if (!(*buffer)[(*read)++])
			return (0);
	if (*read < 4)
		return (0);
	nb = 0;
	i = 0;
	while (i < *read - 3)
	{
		if (((*buffer)[i] < '0' || (*buffer)[i] > '9'))
			return (0);
		nb = nb * 10 + (*buffer)[i++] - '0';
	}
	map->nbr_line = nb;
	map->empty = (*buffer)[i];
	map->wall = (*buffer)[i + 1];
	map->full = (*buffer)[i + 2];
	*buffer += *read + 1;
	return (1);
}

/* FONCTIONS DANS SOLVE() */
int	check_char(t_map *map, char c)
{
	return (c == map->empty || c == map->wall || c == map->full);
}

int	check_line_size(t_map *map, int line_size)
{
	if (!map->line_size)
		map->line_size = line_size;
	return (line_size == map->line_size);
}

int	check_line_count(t_map *map, int y)
{
	return (y == map->nbr_line);
}
