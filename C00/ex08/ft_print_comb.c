#include <unistd.h>
#include <stdio.h>

int ft_pow(int x, int y)
{
	int	res;

	res = 1;
	if (y < 0)
		return (0);
	while (y > 0)
	{
		res = res * x;
		y--;
	}
	return res;
}

int ft_first_nbr(int n)
{
	return
		0 * ft_pow(10, n - 1) +
		1 * ft_pow(10, n - 2) +
		2 * ft_pow(10, n - 3) +
		3 * ft_pow(10, n - 4) +
		4 * ft_pow(10, n - 5) +
		5 * ft_pow(10, n - 6) +
		6 * ft_pow(10, n - 7) +
		7 * ft_pow(10, n - 8) +
		8 * ft_pow(10, n - 9);
}

void ft_putnbr(int nbr, int nbrDigits)
{
	char	mod;
	
	if (nbrDigits == 0) 
		return ;
	if (nbr > 9)
		ft_putnbr(nbr / 10, nbrDigits - 1);
	else if (nbrDigits == 2)
		write(1, "0", 1);

	mod = (nbr % 10) + '0';
	write(1, &mod, 1);
}

int ft_next_nbr(int nbr, int nbrDigits, int i)
{
	int	mod;
	int nextTmp;

	mod = nbr % 10;
	if (nbrDigits == 0)
		return (-1);
	if (mod == 9 - i)
	{
		nextTmp = ft_next_nbr(nbr / 10, nbrDigits - 1, ++i);
		if (nextTmp == -1)
			return (-1);
		nbr = nextTmp * 10 + (nextTmp % 10);
	}
	nbr++;
	return nbr;
}

void	ft_print_combn(int n)
{
	int	nbr;

	nbr = ft_first_nbr(n);
	while (nbr >= 0)
	{
		ft_putnbr(nbr, n);
		nbr = ft_next_nbr(nbr, n, 0);
		if (nbr < 0)
			return ;
		write(1, ", ", 2);
	}
}

int	main(void)
{
	ft_print_combn(4);
	return (0);
}
