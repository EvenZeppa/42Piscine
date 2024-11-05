/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:27:02 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 14:53:54 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (i > j)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

int	ft_get_index_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	sign;
	int	base_len;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	base_len = ft_strlen(base);
	if (!ft_check_base(base))
		return (0);
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (ft_get_index_base(str[i], base) != -1)
	{
		nbr = nbr * base_len + ft_get_index_base(str[i++], base);
	}
	return (nbr * sign);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("La conversion en decimal de '%s' depuis la base '%s' est %d",
		argv[1], argv[2], ft_atoi_base(argv[1], argv[2]));
    }
    return (0);
}
