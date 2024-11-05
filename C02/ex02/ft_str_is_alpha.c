/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:09:21 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/07 17:09:24 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' && str[i] > 'Z') || str[i] < 'A' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

/*int main(int argc, char *argv[])
{
	printf("%d", ft_str_is_alpha(argv[1]));

	return (0);
}*/
