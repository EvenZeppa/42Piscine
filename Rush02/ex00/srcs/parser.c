/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:50:06 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:32 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"

void	parse_dict(t_dict *s_dict, int is_base)
{
	char				*file_buffer;
	char				**split_buffer;
	int					i;
	t_key_value_pair	*elem;

	file_buffer = get_buffer_from_file(s_dict);
	split_buffer = ft_split(file_buffer, ":\n");
	i = 0;
	while (split_buffer[i])
	{
		elem = get_dict_elem_by_key(s_dict, split_buffer[i]);
		if (elem->next == NULL && is_base)
			insertion_s_dict(s_dict,
				ft_atoi_rules(split_buffer[i]),
				ft_trim(split_buffer[i + 1]));
		else if (elem->next != NULL)
			elem->value = ft_trim(split_buffer[i + 1]);
		i += 2;
	}
}
