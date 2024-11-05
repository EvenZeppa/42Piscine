/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:43:13 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 12:58:05 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	tmp_nb;

	tmp_nb = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (tmp_nb > 1)
	{
		nb = nb * (--tmp_nb);
	}
	return (nb);
}

/* int main(int argc,char *argv[])
{
	if (argc == 2)
	{
		printf("La factorielle de %d est : %d",
		atoi(argv[1]), ft_iterative_factorial(atoi(argv[1])));
	}
	return (0);
} */
