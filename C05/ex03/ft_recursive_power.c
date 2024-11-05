/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:04:08 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 13:05:20 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

/* #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("Le resultat de la puissance de %d par %d est %d",
			atoi(argv[1]),
			atoi(argv[2]),
			ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
} */
