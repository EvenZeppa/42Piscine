/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blueprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:10:59 by wifons            #+#    #+#             */
/*   Updated: 2024/09/22 23:43:40 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/ft.h"
#include "../includes/dict_array.h"
#include "../includes/dict.h"

void	number_to_words(int n, t_dict_array *da, char *output)
{
	if (n < 20)
	{
		ft_strcat(output, da->ones[n]);
	}
	else if (n < 100)
	{
		ft_strcat(output, da->tens[n / 10]);
		if (n % 10 != 0)
		{
			ft_strcat(output, " ");
			ft_strcat(output, da->ones[n % 10]);
		}
	}
	else
	{
		ft_strcat(output, da->ones[n / 100]);
		ft_strcat(output, " ");
		ft_strcat(output, da->units[1]);
		if (n % 100 != 0)
		{
			ft_strcat(output, " ");
			number_to_words(n % 100, da, output);
		}
	}
}

void	extract_groups(char *input,
char **groups, int num_groups)
{
	int	len;
	int	start;
	int	group_length;
	int	i;

	len = ft_strlen(input);
	i = 0;
	while (i < num_groups)
	{
		start = len - (i + 1) * GROUP_SIZE;
		if (start < 0)
			group_length = len % GROUP_SIZE;
		else
			group_length = GROUP_SIZE;
		if (group_length == 0)
			group_length = GROUP_SIZE;
		if (start < 0)
			ft_strncpy(groups[i], input + 0, group_length);
		else
			ft_strncpy(groups[i], input + start, group_length);
		groups[i][group_length] = '\0';
		i++;
	}
}

void	process_groups(char **groups, int num_groups, t_dict_array *da)
{
	int		i;
	char	output[100];
	int		number;

	i = num_groups - 1;
	while (i >= 0)
	{
		number = ft_atoi(groups[i]);
		printf("%d\n", number);
		output[0] = '\0';
		if (number != 0)
		{
			number_to_words(number, da, output);
			ft_putstr(output);
			if (i > 0)
			{
				ft_putstr(" ");
				ft_putstr(da->units[i]);
			}
		}
		if (i != 0 && number != 0)
			ft_putstr(" ");
		i--;
	}
	ft_putstr("\n");
}

void	split_input(char *input, t_dict_array *da)
{
	int		len;
	int		num_groups;
	char	**groups;
	int		i;

	len = ft_strlen(input);
	num_groups = (len + GROUP_SIZE - 1) / GROUP_SIZE;
	groups = malloc(num_groups * sizeof(char *));
	i = 0;
	while (i < num_groups)
	{
		groups[i] = malloc((GROUP_SIZE + 1));
		i++;
	}
	extract_groups(input, groups, num_groups);
	process_groups(groups, num_groups, da);
}
