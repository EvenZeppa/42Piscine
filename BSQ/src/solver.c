/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:24:29 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/26 00:35:23 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/print.h"
#include "../includes/validation.h"
#include "../includes/square_engine.h"
#include <stdlib.h>
#include <stdio.h>

/*
	Ajoute dans la map un nombre de carre dependant de range_mask
		si range_mask a un index de zones vides superieur a 0
		alors on ajoute un carre de la size de l'index de range
			a la fin de la liste chainee map
*/
void	square_build(t_map *map, int *range, int *range_mask, int y)
{
	t_square	*new_square;
	t_square	*prev;
	int			x;
	int			i;
	int			is_first;
	(void)		range_mask;

	is_first = add_first_if_null(map);
	prev = get_last_square(map);
	x = 0;
	i = 0;
	while (range[i] != -1)
	{
		if (i % 2 == 0 && range[i] && range[i] > map->size_max)
		{
			new_square = create_square(x, y, range[i]);
			add_square_next_to(new_square, NULL, prev);
			prev = new_square;
		}
		x += range[i];
		i++;
	}
	if (is_first)
		delete_square(map, map->first);
}

/* Incremente le buffer, et le tableau de range de 1 */
int	increment_buffer_range(char **buffer, int **range, int **range_mask, int i)
{
	if ((*range)[i] == -1)
		(*range)[i] = 0;
	if ((*range_mask)[i] == -1)
		(*range_mask)[i] = 0;
	(*range)[i] += 1;
	(*range_mask)[i] += 1;
	(*buffer)++;
	return (1);
}

/*
	Genere le tableau de range de la ligne avec
		index pair -> range des zones vides
		index impair -> range des zones obstacles
	Retourne la taille de la ligne parcourue
*/
int	range_gen(char **buffer, t_map *map, int **range, int **range_mask)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = 0;
	i = 0;
	while (*(*buffer) != '\n')
	{
		if (!check_char(map, *(*buffer)))
			return (-1);
		if (i % 2 == 0)
			while (*(*buffer) == map->empty)
				line_size += increment_buffer_range(buffer, range, range_mask, i);
		else
			while (*(*buffer) == map->wall)
				line_size += increment_buffer_range(buffer, range, range_mask, i);
		i++;
	}
	if (!check_line_size(map, line_size))
		return (-1);
	return (line_size);
}

/*
	Alloue la memoire necessaire aux 2 tableaux de range,
		Retourne (1) si reussi, sinon (0)
*/
int	malloc_ranges(char *buffer, int **range, int **range_mask)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
			return (0);
		i++;
	}
	(*range) = malloc(sizeof(int) * i + 1);
	if (!range)
		return (0);
	(*range_mask) = malloc(sizeof(int) * i + 1);
	if (!(*range_mask))
		return (0);
	j = 0;
	while (j < i)
	{
		(*range)[j] = -1;
		(*range_mask)[j] = -1;
		j++;
	}
	return (1);
}

void	reset_ranges(int **range, int **range_mask, int line_size)
{
	int	j;

	j = 0;
	while (j < line_size)
	{
		(*range)[j] = -1;
		(*range_mask)[j] = -1;
		j++;
	}
}

/*
	Fonction qui va lancer toutes les instructions de l'algorithme
		Retourne (1) si une solution est trouvee
		Si une erreur s'est produite ou aucune solution n'est trouvee (-1)
*/
int	solve(t_map *map, char *buffer, int size_buffer)
{
	int	*range;
	int	*range_mask;
	int	len;
	int	y;
	(void)	size_buffer;

	if (!malloc_ranges(buffer, &range, &range_mask))
		return (0);
	len = 0;
	y = 0;
	while (y < map->nbr_line)
	{
		reset_ranges(&range, &range_mask, map->line_size + 1);
		len = range_gen(&buffer, map, &range, &range_mask);
		if (len == -1)
			return (0);
		range_mask = square_engine(map, &range, &range_mask, y);
		square_build(map, range, range_mask, y);
		buffer++;
		y++;
		printf("x : %d y : %d size: %d\n", map->x_max, map->y_max, map->size_max);
	}
	buffer -= y * (map->line_size + 1);
	if (map->size_max == 0 || !check_line_count(map, y))
		return (free(range), free(range_mask), 0);
	return (free(range), free(range_mask), 1);
}
