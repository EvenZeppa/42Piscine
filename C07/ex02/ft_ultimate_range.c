/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:29:51 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/17 11:23:17 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	if (size <= 0)
	{
		range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		range[0][i] = min + i;
		i++;
	}
	return (size);
}

/* #include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	if (argc == 3)
	{
		size = ft_ultimate_range(&tab, atoi(argv[1]), atoi(argv[2]));
		printf("%d\n", size);
		while(i < atoi(argv[2]) - atoi(argv[1]))
			printf("%d\n", tab[i++]);
	}
	return (0);
} */
