/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:52:23 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/08 22:24:10 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	row_start(int i, int x)
{
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('/');
		else if (i == x)
			ft_putchar('\\');
		else
			ft_putchar('*');
		i++;
	}
	return (i);
}

int	row_end(int i, int x)
{
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('\\');
		else if (i == x)
			ft_putchar('/');
		else
			ft_putchar('*');
		i++;
	}
	return (i);
}

int	row_inter(int i, int x)
{
	while (i <= x)
	{
		if (i == 1 || i == x)
			ft_putchar('*');
		else
			ft_putchar(' ');
		i++;
	}
	return (i);
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (x <= 0 || y <= 0)
	{
		write(1, "La colonne / la ligne est inferieure a 1, reessaye ! <3", 56);
		return ;
	}
	while (j <= y)
	{
		i = 1;
		if (j == 1)
			i = row_start(i, x);
		else if (j == y)
			i = row_end(i, x);
		else
			i = row_inter(i, x);
		j++;
		ft_putchar('\n');
	}
}
