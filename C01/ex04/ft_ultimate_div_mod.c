/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:09:09 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/05 18:10:20 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a / *b;
	*b = *a % *b;
	*a = c;
}

/*int main(void)
{
	int a;
	int b;
	int *pa;
	int *pb;

	a = 50;
	b = 12;
	pa = &a;
	pb = &b;

	printf("Valeurs de a et b : a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(pa, pb);
	printf("Valeurs de *pa et *pb : a = %d, b = %d", *pa, *pb);
	
	return (0);
}*/
