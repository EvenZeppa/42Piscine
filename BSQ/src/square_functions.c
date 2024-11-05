/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:09:30 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/26 00:50:00 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include <stdlib.h>
#include <stdio.h>

/* Cree et renvoie un nouvel element carre */
t_square	*create_square(int x, int y, int size)
{
	t_square	*new_square;

	new_square = malloc(sizeof(t_square));
	if (!new_square)
		return (0);
	new_square->x = x;
	new_square->y = y;
	new_square->size = size;
	new_square->initial_size = size;
	return (new_square);
}

/*
	Ajoute le carre donne a la suite de celui fournit,
	le place au debut de la map si on envoie NULL
*/
t_square	*add_square_next_to(t_square *new, t_map *map, t_square *prev)
{
	t_square	*tmp_next;

	if (!prev && map)
	{
		tmp_next = map->first;
		tmp_next->prev = new;
		new->prev = NULL;
		new->next = tmp_next;
		map->first = new;
	}
	else if (new)
	{
		tmp_next = prev->next;
		tmp_next->prev = new;
		new->prev = prev;
		new->next = tmp_next;
		prev->next = new;
	}
	return (new);
}

/* Supprime un element donne de la map */
void	delete_square(t_map *map, t_square *square)
{
	t_square	*tmp_prev;
	t_square	*tmp_next;

	if (!square->prev && map)
	{
		tmp_next = square->next;
		tmp_next->prev = NULL;
		square->next = NULL;
		map->first = tmp_next;
	}
	else
	{
		tmp_prev = square->prev;
		tmp_next = square->next;
		tmp_prev->next = tmp_next;
		tmp_next->prev = tmp_prev;
		square->prev = NULL;
		square->next = NULL;
	}
	free(square);
}

/* Renvoie le dernier element de la map, NULL si vide */
t_square	*get_last_square(t_map *map)
{
	t_square	*current;

	current = map->first;
	if (!current->next)
		return (NULL);
	while (current->next && current->next->next)
		current = current->next;
	return (current);
}
