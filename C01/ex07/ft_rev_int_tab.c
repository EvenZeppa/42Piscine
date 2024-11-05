/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:58:57 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/10 13:52:50 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	temp1;

	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		temp1 = tab[size - 1];
		tab[i] = temp1;
		tab[size - 1] = temp;
		i++;
		size--;
	}
}

/*int main()
{
	int tab[] = {1,2,3,4,5};
	int i = 0;

	ft_rev_int_tab(tab, 5);
	while (i < 5)
	{
		printf("%d, ", tab[i]);
		i++;
	}

	return (0);
}*/
