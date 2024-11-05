/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:33:23 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 13:47:22 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	printf("Les chaines a comparer sont : '%s' et '%s'",
		argv[1], argv[2]);
	printf("La comparaison des 2 chaines renvoie : %d",
		ft_strcmp(argv[1], argv[2]));
	printf("La comparaison des 2 chaines renvoie : %d",
		strcmp(argv[1], argv[2]));
	return (0);
}*/