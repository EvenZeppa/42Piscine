/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:23:11 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/12 19:13:31 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_can_place(int col, int row, int *queens)
{
	int	diag_up;
	int	diag_down;
	int	first_occurence;

	first_occurence = 1;
	diag_up = row;
	diag_down = row;
	while (col >= 0)
	{
		if (first_occurence == 0)
		{
			if (diag_up == queens[col]
				|| row == queens[col]
				|| diag_down == queens[col])
				return (0);
		}
		first_occurence = 0;
		diag_up++;
		diag_down--;
		col--;
	}
	return (1);
}

int	ft_next_col(int col, int row, int *queens, int count)
{
	char	c;
	int		i;

	i = 0;
	while (row < 10)
	{
		if (ft_can_place(col, row, queens) == 1)
		{
			queens[col] = row;
			if (col == 9)
			{
				while (i < 10)
				{
					c = queens[i++] + '0';
					write(1, &c, 1);
				}
				i = 0;
				write(1, "\n", 1);
				count++;
			}
			count = ft_next_col(col + 1, 0, queens, count);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];

	return (ft_next_col(0, 0, queens, 0));
}

/* int main()
{
    ft_ten_queens_puzzle();
    return 0;
} */
