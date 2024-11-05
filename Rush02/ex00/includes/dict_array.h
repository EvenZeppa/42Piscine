/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_array.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:44:48 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:57 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_ARRAY_H
# define DICT_ARRAY_H

typedef struct s_dict_array
{
	char	**ones;
	char	**tens;
	char	**units;
}	t_dict_array;

void	split_input(char *input, t_dict_array *da);
void	number_to_words(int n, t_dict_array *da, char *output);

#endif
