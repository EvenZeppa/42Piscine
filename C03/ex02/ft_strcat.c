/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:07:16 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/09 20:12:09 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*int	main(int argc,char *argv[])
{
	char cpy[] = "0123456789";
	char cpy1[] = "0123456789";

	strcpy(cpy, argv[1]);
	strcpy(cpy1, argv[2]);
	if (argc == 3)
		printf("La chaine concatenee de '%s' et '%s' est '%s'",
			cpy1, cpy, ft_strcat(argv[2], argv[1]));
	return (0);
}*/
