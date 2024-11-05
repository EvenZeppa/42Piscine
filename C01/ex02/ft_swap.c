/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:05:02 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/05 18:15:22 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*int main(void)
{
	int a;
	int b;
	int *pa;
	int *pb;
	
	a = 0;
	b = 42;
	printf("Valeurs : a = %d, b = %d\n", a, b);
	pa = &a;
	pb = &b;

	ft_swap(pa, pb);
	printf("Nouvelles valeurs : a = %d, b = %d", *pa, *pb);
	return (0);
}*/
