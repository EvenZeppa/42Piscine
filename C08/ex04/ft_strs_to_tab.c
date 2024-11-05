/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:05:27 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/19 16:33:39 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, src);
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_tab;
	int			i;

	s_tab = malloc(sizeof(t_stock_str) * ac + 1);
	if (!s_tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		s_tab[i].size = ft_strlen(av[i]);
		s_tab[i].str = av[i];
		s_tab[i].copy = ft_strdup(av[i]);
		if (!s_tab[i - 1].copy)
			free(s_tab[i - 1].copy);
		i++;
	}
	s_tab[i].str = 0;
	return (s_tab);
}

/* int	main(int argc, char *argv[])
{
	if (argc > 2)
	{
		int		size = atoi(argv[1]);
		char	**strs;
		int		i = 0;
		t_stock_str *strs_tab;

		strs = malloc(sizeof(char *) * size);
		while (i < size)
		{
			strs[i] = malloc(sizeof(char) * ft_strlen(argv[i + 2]));
			strs[i] = argv[i + 2];
			i++;
		}
		strs_tab = ft_strs_to_tab(size, strs);
		ft_show_tab(strs_tab);
	}
	return (0);
} */
