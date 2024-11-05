/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:15:39 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:36:28 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/dict_array.h"
#include "../includes/memory.h"

int	is_valid_file(t_dict *dict)
{
	char	*buffer;
	int		i;

	buffer = get_buffer_from_file(dict);
	i = 0;
	while (buffer[i])
	{
		while (buffer[i] == ' ' || (buffer[i] >= 9 && buffer[i] <= 13))
			i++;
		if (buffer[i] == '+' || buffer[i] == '-')
			i++;
		while (ft_isdigit(buffer[i]))
			i++;
		while (buffer[i] != ':')
			i++;
		if (buffer[i] != ':')
			return (0);
		while (buffer[i] == ' ')
			i++;
		while (ft_isprint(buffer[i]))
			i++;
		if (buffer[i++] != '\n')
			return (0);
	}
	return (1);
}

int	initialize_dict(t_dict *dict)
{
	dict->selected_path = DICT_PATH;
	if (dict != NULL)
	{
		if (is_valid_file(dict))
		{
			parse_dict(dict, TRUE);
		}
		else
		{
			ft_putstr(DICT_ERROR);
		}
	}
	return (1);
}

int	check_cond(int argc, char *argv[], char **dict_path, char **nbr)
{
	(*dict_path) = malloc(1028);
	(*nbr) = malloc(1028);
	if (argc == 3)
	{
		*dict_path = argv[1];
		*nbr = argv[2];
	}
	else
	{
		*dict_path = DICT_PATH;
		*nbr = argv[1];
	}
	if ((*nbr)[0] == '-')
	{
		ft_putstr(ARG_ERROR);
		return (0);
	}
	return (1);
}

t_dict_array	*initialize_dict_array(
	t_dict_array **dict_array, t_dict *dict_base)
{
	(*dict_array) = malloc(sizeof(dict_array));
	(*dict_array)->ones = get_ones_array(dict_base);
	(*dict_array)->tens = get_tens_array(dict_base);
	(*dict_array)->units = get_units_array(dict_base);
	return (*dict_array);
}

int	main(int argc, char *argv[])
{
	t_dict			*dict_base;
	t_dict_array	*dict_array;
	char			*dict_path;
	char			*nbr;

	if (argc == 2 || argc == 3)
	{
		if (!check_cond(argc, argv, &dict_path, &nbr))
			return (1);
		dict_base = initialize_s_dict();
		if (!initialize_dict(dict_base))
			return (1);
		if (argc == 3)
		{
			dict_base->selected_path = dict_path;
			if (is_valid_file(dict_base))
				parse_dict(dict_base, FALSE);
			else
				return (1);
		}
		dict_array = initialize_dict_array(&dict_array, dict_base);
		split_input(nbr, dict_array);
		free_all(dict_base, dict_array);
	}
	return (0);
}
