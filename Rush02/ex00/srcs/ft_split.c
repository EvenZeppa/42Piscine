/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:22:49 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:32 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"

int	str_charset_len(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (is_charset(str, charset))
			return (count);
		count++;
		str++;
	}
	return (count);
}

int	ft_total_len(char *str, char *charset)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (is_charset(str, charset))
		{
			if (is_word)
			{
				count++;
				is_word = 0;
			}
		}
		else
			is_word = 1;
		str++;
	}
	if (is_word)
		count++;
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		str_len;
	int		total_len;

	total_len = ft_total_len(str, charset);
	strs = malloc(sizeof(char *) * (total_len + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		while (is_charset(str, charset))
			str += ft_total_len(str, "\0");
		str_len = str_charset_len(str, charset);
		strs[i] = malloc(sizeof(char) * str_len + 1);
		if (!strs[i])
			return (NULL);
		strs[i] = ft_strncpy(strs[i], str, str_len);
		strs[i][str_len] = '\0';
		str += str_len;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
