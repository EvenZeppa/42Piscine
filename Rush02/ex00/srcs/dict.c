/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:10:45 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:32 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"

t_dict	*initialize_s_dict(void)
{
	t_dict				*dict;
	t_key_value_pair	*first_elem;

	dict = malloc(sizeof(dict));
	first_elem = malloc(sizeof(t_key_value_pair));
	if (dict == NULL || first_elem == NULL)
		return (NULL);
	first_elem->key = "\0";
	first_elem->value = "\0";
	first_elem->next = NULL;
	dict->first = first_elem;
	return (dict);
}

void	insertion_s_dict(t_dict *dict, char *key, char *value)
{
	t_key_value_pair	*new_elem;

	new_elem = malloc(sizeof(t_key_value_pair));
	if (dict == NULL || new_elem == NULL)
		return ;
	new_elem->key = key;
	new_elem->value = value;
	new_elem->next = dict->first;
	dict->first = new_elem;
}

t_key_value_pair	*get_dict_elem_by_key(t_dict *dict, char *key)
{
	t_key_value_pair	*current;

	if (dict == NULL)
		return (NULL);
	current = dict->first;
	while (current->next != NULL)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (current);
}

void	print_s_dict(t_dict *dict)
{
	t_key_value_pair	*current;

	if (dict == NULL)
		return ;
	current = dict->first;
	while (current->next != NULL)
	{
		ft_putstr("key: ");
		ft_putstr(current->key);
		ft_putstr(", value: ");
		ft_putstr(current->value);
		ft_putstr("\n");
		current = current->next;
	}
	ft_putstr("NULL");
}
