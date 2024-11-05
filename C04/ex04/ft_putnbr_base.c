/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:13:10 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 19:01:17 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	char	c;

	len_base = ft_strlen(base);
	if (!ft_check_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > len_base - 1)
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putnbr_base(nbr % len_base, base);
	}
	else
	{
		c = base[nbr];
		write(1, &c, 1);
	}
}

/*#include <stdio.h>
#include "../ex03/ft_atoi.c"

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        ft_putnbr_base(ft_atoi(argv[1]), argv[2]);
    }
    return (0);
}*/
