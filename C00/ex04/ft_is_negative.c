/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:16:15 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/05 07:35:07 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	pc;
	char	nc;

	pc = 'P';
	nc = 'N';
	if (n < 0)
	{
		write(1, &nc, 1);
	}
	else
	{
		write(1, &pc, 1);
	}
}

/*int main(void)
{
	ft_is_negative(-42);
	ft_is_negative(0);
	ft_is_negative(42);
	return (0);
}*/
