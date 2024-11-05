/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:52:26 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/26 21:07:55 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_nbr(int nb)
{
	char	mod;

	mod = (nb % 10) + '0';
	if (nb > 9)
	{
		ft_put_nbr(nb / 10);
	}
	write(1, &mod, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i <= 9)
				write(1, "0", 1);
			ft_put_nbr(i);
			write(1, " ", 1);
			if (j <= 9)
				write(1, "0", 1);
			ft_put_nbr(j);
			if (i != 98 || j != 99)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

/* int main()
{
	ft_print_comb2();

	return 0;
} */
