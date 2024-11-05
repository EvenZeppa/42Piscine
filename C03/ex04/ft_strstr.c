/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:07:56 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 21:58:50 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		while (str[i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
			{
				return (str);
			}
			i++;
		}
		i = 0;
		str++;
	}
	return ("\0");
}

/*int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("La chaine a chercher est '%s'\n", argv[1]);
        printf("La chaine a trouver est '%s'\n", argv[2]);
        printf("Resultat : '%s'", ft_strstr(argv[1], argv[2]));
    }
    return (0);
}*/