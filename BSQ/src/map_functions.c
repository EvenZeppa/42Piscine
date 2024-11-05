/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:13:33 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 13:03:02 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdlib.h>
#include <stdio.h>

/* Initialise une nouvelle map avec les valeurs par defaut */
t_map	*init_map(void)
{
	t_map		*new_map;
	t_square	*first_square;

	new_map = malloc(sizeof(t_map));
	first_square = malloc(sizeof(t_square));
	first_square->prev = NULL;
	first_square->next = NULL;
	new_map->first = first_square;
	new_map->x_max = 0;
	new_map->y_max = 0;
	new_map->size_max = 0;
	new_map->line_size = 0;
	return (new_map);
}

/*
	Ajoute un carre au debut de la liste si elle est vide
	Retourne (0) s'il y a deja des carres, sinon (1)
*/
int	add_first_if_null(t_map *map)
{
	t_square	*new_square;

	if (!(map->first->next))
	{
		new_square = create_square(0, 0, 0);
		add_square_next_to(new_square, map, NULL);
		return (1);
	}
	return (0);
}

/* Free l'ensemble des carres dans la liste , puis la liste */
void	free_map(t_map *map)
{
	t_square	*next;
	t_square	*current;

	current = map->first;
	while (current->next)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(next);
	free(map);
}
