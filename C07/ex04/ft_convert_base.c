/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:28:23 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/26 21:17:51 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);
int	ft_check_base(char *base);
int	ft_strlen(char *str);
int	ft_get_index_base(char c, char *base);

int	ft_nbr_to_base_len(int nbr, int base_len)
{
	int	count;

	count = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 0)
	{
		nbr = nbr / base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		base_len;
	int		nbr_to_base_len;
	char	*str;

	base_len = ft_strlen(base);
	nbr_to_base_len = ft_nbr_to_base_len(nbr, base_len);
	if (!ft_check_base(base) || nbr == -2147483648)
		return (NULL);
	nbr_to_base_len = nbr_to_base_len + (nbr < 0);
	str = malloc(sizeof(char) * nbr_to_base_len + 1);
	if (str == NULL)
		return (NULL);
	str[nbr_to_base_len] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[nbr_to_base_len - 1] = base[nbr % base_len];
		nbr = nbr / base_len;
		nbr_to_base_len--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	first_conv;

	first_conv = ft_atoi_base(nbr, base_from);
	if (first_conv == 0)
		return ("0");
	return (ft_itoa_base(first_conv, base_to));
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char	*nb = argv[1];
		char	*base_from = argv[2];
		char	*base_to = argv[3];

		printf("La conversion est : %s"
			, ft_convert_base(nb, base_from, base_to));
	}
	return (0);
}
