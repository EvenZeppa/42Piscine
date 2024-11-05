/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:22:49 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/20 20:51:25 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_charset(char *str, char *charset)
{
	while (*charset)
	{
		if (*str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

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

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
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
	strs[i] = 0;
	return (strs);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char	*str = argv[1];
		char	*charset = argv[2];
		char	**strs;

		strs = ft_split(str, charset);
		while (*strs)
		{
			printf("%s\n", *strs);
			strs++;
		}
	}
	return (0);
} */
