/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:07:16 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 12:31:23 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc,char *argv[])
{
	if (argc == 4)
		printf("La chaine concatenee de '%s' et '%s' est '%s'\n",
			argv[2], argv[1], ft_strncat(argv[2], argv[1], atoi(argv[3])));
		printf("La chaine concatenee de '%s' et '%s' est '%s'",
			argv[2], argv[1], strncat(argv[2], argv[1], atoi(argv[3])));
	return (0);
} */