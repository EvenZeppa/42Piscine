/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:49:51 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 13:00:50 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

/* #include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	if (argc == 2)
	{
		printf("La factorielle de %d est : %d",
		 atoi(argv[1]), ft_recursive_factorial(atoi(argv[1])));
	}
	return (0);
} */
