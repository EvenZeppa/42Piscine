/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:04:35 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:36:39 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_trim(char *str)
{
	int		i;
	int		count;
	char	*dest;

	while (*str && *str == ' ')
		str++;
	i = 0;
	count = 0;
	while (str[i] && str[i] != ' ')
	{
		count++;
		i++;
	}
	dest = malloc(sizeof(char) * (count + 1));
	i = 0;
	while (i < count)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_atoi_rules(char *str)
{
	int		i;
	int		count;
	char	*dest;

	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	i = 0;
	count = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		count++;
		i++;
	}
	dest = malloc(sizeof(char) * (count + 1));
	i = 0;
	while (i < count)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
