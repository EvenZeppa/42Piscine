/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:19:28 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/05 18:09:44 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int main(void)
{
	int a;
	int b;
	int pa;
	int pb;
	int *div;
	int *mod;

	a = 50;
	b = 12;
	printf("Valeurs des variables : a = %d, b = %d\n", a, b);
	div = &pa;
	mod = &pb;
	ft_div_mod(a, b, div, mod);
	printf("Valeur des pointeurs : div = %d, mod = %d", *div, *mod);
	return (0);
}*/
