/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:49:57 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 13:17:24 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = nb - 1;
	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	while (i >= 2)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

/* #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Le prochain nombre premier a partir de '%d' est : %d",
		atoi(argv[1]), ft_find_next_prime(atoi(argv[1])));
	}
	return (0);
} */
