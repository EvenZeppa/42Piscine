/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:37:40 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/24 22:43:47 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	is_sorted;
	int	tmp;
	int	i;

	is_sorted = 0;
	while (is_sorted == 0)
	{
		is_sorted = 1;
		i = 0;
		while (tab[i + 1] != 0)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				is_sorted = 0;
			}
			i++;
		}
	}
}

/*int main(void)
{
	int i;
	int array_nbr[] = {5,9,4,3,7,1,0};

	ft_sort_int_tab(array_nbr, 7);

	i = 0;
	while(i < 7)
	{
		printf("%d\n", array_nbr[i]);
		i++;
	}

	return (0);
}*/
