/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:34:08 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:35:18 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/dict_array.h"

void	free_all(t_dict *dict, t_dict_array *da)
{
	t_key_value_pair	*current;
	t_key_value_pair	*next;

	current = dict->first;
	while (current->next != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(dict);
	free(da->ones);
	free(da->tens);
	free(da->units);
}
