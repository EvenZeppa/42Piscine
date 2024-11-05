/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:51:15 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 13:02:58 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	power_tmp;

	power_tmp = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power-- > 1)
	{
		nb *= power_tmp;
	}
	return (nb);
}

/* #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("Le resultat de la puissance de %d par %d est %d",
			atoi(
				argv[1]),
				atoi(argv[2]),
				ft_iterative_power(atoi(argv[1]), atoi(argv[2])
				)
			);
	}
	return (0);
} */
