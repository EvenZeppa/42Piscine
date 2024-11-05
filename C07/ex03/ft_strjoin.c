/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:46:28 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/24 18:00:52 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_total_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	sep_size;
	int	i;

	total_size = 0;
	sep_size = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		if (i != size - 1)
			total_size += sep_size;
		i++;
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		total_size;
	int		i;

	if (size == 0 || strs == NULL)
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	total_size = ft_total_size(size, strs, sep);
	str = malloc(sizeof(char) * total_size + 1);
	str[0] = '\0';
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i != size - 1)
			ft_strcat(str, sep);
		i++;
	}
	str[total_size] = '\0';
	return (str);
}

/* int	main(int argc, char *argv[])
{
	char	**strs;
	char	*sep = argv[1];
	char	*str;
	int		i;

	strs = malloc(sizeof(char *) * argc - 2);
	i = 0;
	while (i < argc - 2)
	{
		strs[i] = malloc(sizeof(char) * ft_strlen(argv[i + 2]));
		strs[i] = argv[i  + 2];
		printf("%s\n", strs[i]);
		i++;
	}

	str = ft_strjoin(argc - 2, strs, sep);
	printf("Apres str_join : '%s'", str);
	free(str);
	return (0);
} */
