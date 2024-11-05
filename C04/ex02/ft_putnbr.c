/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:23:09 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/21 12:25:30 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

/*int ft_atoi(char *str)
{
    int nbr;

    nbr = 0;
    while (*str)
    {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }

    return nbr;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        ft_putnbr(ft_atoi(argv[1]));
    }
    return (0);
}*/
