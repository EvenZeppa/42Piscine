/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:46:17 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 18:44:46 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && i < n - 1)
	{
		i++;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 4)
		printf("La comparaison de la chaine '%s' et '%s' retourne %d\n",
			argv[1], argv[2], ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("La comparaison de la chaine '%s' et '%s' retourne %d",
			argv[1], argv[2], strncmp(argv[1], argv[2], atoi(argv[3])));
	return (0);
} */
