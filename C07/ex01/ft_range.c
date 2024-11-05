/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:13:48 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/17 11:23:22 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	size;
	int	i;

	size = max - min;
	if (size <= 0)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
/* #include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*tab;
	int	i;

	i = 0;
	if (argc == 3)
	{
		tab = ft_range(atoi(argv[1]), atoi(argv[2]));
		while(i < atoi(argv[2]) - atoi(argv[1]))
			printf("%d\n", tab[i++]);
	}
	return (0);
} */
