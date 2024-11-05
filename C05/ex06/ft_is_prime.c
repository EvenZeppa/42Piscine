/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:04:54 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 13:10:07 by ezeppa           ###   ########.fr       */
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

/* #include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("Le nombre %d est (1):premier, (0)ou non -> %d",
			atoi(argv[1]),
			ft_is_prime(atoi(argv[1])));
	}

	return (0);
} */
