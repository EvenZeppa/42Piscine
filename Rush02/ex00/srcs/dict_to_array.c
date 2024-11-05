/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:16:20 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:40:11 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"

char	**maloc_all(int size)
{
	char	**strs;
	int		i;

	strs = malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		strs[i] = malloc(1024);
		i++;
	}
	return (strs);
}

char	**get_ones_array(t_dict *dict)
{
	char	**array;

	array = maloc_all(20);
	array[0] = (*get_dict_elem_by_key(dict, "0")).value;
	array[1] = (*get_dict_elem_by_key(dict, "1")).value;
	array[2] = (*get_dict_elem_by_key(dict, "2")).value;
	array[3] = (*get_dict_elem_by_key(dict, "3")).value;
	array[4] = (*get_dict_elem_by_key(dict, "4")).value;
	array[5] = (*get_dict_elem_by_key(dict, "5")).value;
	array[6] = (*get_dict_elem_by_key(dict, "6")).value;
	array[7] = (*get_dict_elem_by_key(dict, "7")).value;
	array[8] = (*get_dict_elem_by_key(dict, "8")).value;
	array[9] = (*get_dict_elem_by_key(dict, "9")).value;
	array[10] = (*get_dict_elem_by_key(dict, "10")).value;
	array[11] = (*get_dict_elem_by_key(dict, "11")).value;
	array[12] = (*get_dict_elem_by_key(dict, "12")).value;
	array[13] = (*get_dict_elem_by_key(dict, "13")).value;
	array[14] = (*get_dict_elem_by_key(dict, "14")).value;
	array[15] = (*get_dict_elem_by_key(dict, "15")).value;
	array[16] = (*get_dict_elem_by_key(dict, "16")).value;
	array[17] = (*get_dict_elem_by_key(dict, "17")).value;
	array[18] = (*get_dict_elem_by_key(dict, "18")).value;
	array[19] = (*get_dict_elem_by_key(dict, "19")).value;
	return (array);
}

char	**get_tens_array(t_dict *dict)
{
	char	**array;

	array = maloc_all(10);
	array[0] = "";
	array[1] = "";
	array[2] = (*get_dict_elem_by_key(dict, "20")).value;
	array[3] = (*get_dict_elem_by_key(dict, "30")).value;
	array[4] = (*get_dict_elem_by_key(dict, "40")).value;
	array[5] = (*get_dict_elem_by_key(dict, "50")).value;
	array[6] = (*get_dict_elem_by_key(dict, "60")).value;
	array[7] = (*get_dict_elem_by_key(dict, "70")).value;
	array[8] = (*get_dict_elem_by_key(dict, "80")).value;
	array[9] = (*get_dict_elem_by_key(dict, "90")).value;
	return (array);
}

char	**get_units_array(t_dict *dict)
{
	char	**array;

	array = maloc_all(14);
	array[0] = "";
	array[1] = (*get_dict_elem_by_key(dict, "100")).value;
	array[2] = (*get_dict_elem_by_key(dict, "1000")).value;
	array[3] = (*get_dict_elem_by_key(dict, "1000000")).value;
	array[4] = (*get_dict_elem_by_key(dict, "1000000000")).value;
	array[5] = (*get_dict_elem_by_key(dict, "1000000000000")).value;
	array[6] = (*get_dict_elem_by_key(dict, "1000000000000000")).value;
	array[7] = (*get_dict_elem_by_key(dict, "1000000000000000000")).value;
	array[8] = (*get_dict_elem_by_key(dict, "1000000000000000000000")).value;
	array[9] = (*get_dict_elem_by_key(dict, "1000000000000000000000000")).value;
	array[10] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000")).value;
	array[11] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000000")).value;
	array[12] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000000000")).value;
	array[13] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000000000000")).value;
	return (array);
}

char	**get_group_units_array(t_dict *dict)
{
	char	**array;

	array = maloc_all(14);
	array[0] = "";
	array[1] = (*get_dict_elem_by_key(dict, "1000")).value;
	array[2] = (*get_dict_elem_by_key(dict, "1000000")).value;
	array[3] = (*get_dict_elem_by_key(dict, "1000000000")).value;
	array[4] = (*get_dict_elem_by_key(dict, "1000000000000")).value;
	array[5] = (*get_dict_elem_by_key(dict, "1000000000000000")).value;
	array[6] = (*get_dict_elem_by_key(dict, "1000000000000000000")).value;
	array[7] = (*get_dict_elem_by_key(dict, "1000000000000000000000")).value;
	array[8] = (*get_dict_elem_by_key(dict, "1000000000000000000000000")).value;
	array[9] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000")).value;
	array[10] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000000")).value;
	array[11] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000000000")).value;
	array[12] = (*get_dict_elem_by_key(dict,
				"1000000000000000000000000000000000000")).value;
	return (array);
}
