/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:48:31 by wifons            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:32 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	return (
		c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
	);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	handle_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -sign;
		}
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_whitespace(str[i]))
		i++;
	sign = handle_sign(str, &i);
	while (is_digit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>

// void run_test(char *str)
// {
// 	printf("Input: \"%s\" => Output: %d\n", str, ft_atoi(str));
// }

// int main()
// {
// 	run_test("42");
// 	run_test("   -42");
// 	run_test("4193 with words");
// 	run_test("words and 987");
// 	run_test("   +0");
// 	run_test("   -0");
// 	run_test("2147483647");
// 	run_test("-2147483648");
// 	run_test("   +2147483647");
// 	run_test("   -2147483648");
// 	run_test("   +000123");
// 	run_test("   -000123");
// 	run_test("   +123abc456");
// 	run_test("   -123abc456");
// 	return 0;
// }