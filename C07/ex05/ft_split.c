/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:32:39 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/18 13:57:02 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

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

int	is_charset(char *str, char *charset)
{
	while (*charset)
	{
		if (*str != *charset)
			return (0);
		charset++;
		str++;
	}
	return (1);
}

unsigned int	count_letters_until_charset(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!(*charset))
	{
		while (str[count])
		{
			count++;
		}
		return (count);
	}
	while (is_charset(&str[i], charset))
		i += count_letters_until_charset(charset, "\0");
	while (str[i] && !is_charset(&str[i++], charset))
		count++;
	return (count);
}

unsigned int	count_total_nbr(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (is_charset(str, charset))
			str += count_letters_until_charset(charset, "\0");
		else if (*str)
		{
			str += count_letters_until_charset(str, charset);
			count++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char			**strs;
	unsigned int	i;
	unsigned int	total_nbr_list;
	unsigned int	len_next_word;

	total_nbr_list = count_total_nbr(str, charset);
	strs = malloc(sizeof(char *) * total_nbr_list + 1);
	if (strs == NULL)
		return (NULL);
	strs[total_nbr_list] = 0;
	i = 0;
	while (i < total_nbr_list)
	{
		while (is_charset(str, charset))
			str += count_letters_until_charset(charset, "\0");
		len_next_word = count_letters_until_charset(str, charset);
		strs[i] = malloc(sizeof(char) * len_next_word + 1);
		ft_strncpy(strs[i], str, len_next_word);
		strs[i][len_next_word] = '\0';
		str += len_next_word;
		i++;
	}
	return (strs);
}

/* int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char *str = argv[1];
		char *charset = argv[2];
		char **strs;

		strs = ft_split(str, charset);

		while (*strs)
		{
			printf("%s\n", *strs++);
		}
	}
	return (0);
} */
