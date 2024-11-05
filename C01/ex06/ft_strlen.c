/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:48:26 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 13:49:26 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	nbr;

	while (*str != '\0')
	{
		nbr++;
		str++;
	}
	return (nbr);
}

/*int main(void)
{
	printf("Nombre de caracteres : %d", ft_strlen("Colomb"));

	return (0);
}*/
