/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:14:46 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 18:58:11 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

/*int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("La taille de la chaine '%s' est de %d",
		argv[1], ft_strlen(argv[1]));
    }
    return (0);
}*/
