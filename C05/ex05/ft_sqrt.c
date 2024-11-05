/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:18:24 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 13:08:58 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	pow;
	int	i;

	pow = 0;
	i = 0;
	if (nb <= 0)
		return (0);
	while (nb != pow)
	{
		pow = i * i;
		if (pow > nb)
			return (0);
		i++;
	}
	return (i - 1);
}
/* #include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("La racine carre de %d est : %d",
		atoi(argv[1]), ft_sqrt(atoi(argv[1])));
	}

	return (0);
} */
