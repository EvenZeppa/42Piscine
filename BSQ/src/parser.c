/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeel-qai <jeel-qai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:52:40 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 18:51:32 by jeel-qai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* Réalloue une chaine de caractère à 'size' et la retourne terminé par null */
char	*ft_reallocstr(char *ptr, size_t size)
{
	char	*resized;
	int		i;

	if (!ptr)
		return (malloc(size));
	resized = malloc(size);
	i = 0;
	while (ptr[i])
	{
		resized[i] = ptr[i];
		i++;
	}
	resized[i] = '\0';
	free(ptr);
	return (resized);
}

/* Lie en utilisant un buffer de taille dynamique et renvoie le nombre 		*/
/* d'octect lu 																*/
int	dynamic_read(int fd, int len, char **buffer)
{
	int	buffer_size;

	buffer_size = PAGE_SIZE;
	while (len == buffer_size)
	{
		if (*(*buffer + PAGE_SIZE) != '\0')
			buffer_size *= BUFFER_MULT;
		*buffer = ft_reallocstr(*buffer, buffer_size * BUFFER_MULT + 1);
		len = read(fd, *buffer + buffer_size, buffer_size);
		*(*buffer + buffer_size * BUFFER_MULT) = '\0';
	}
	close(fd);
	*(*buffer + buffer_size + len) = '\0';
	return (buffer_size + len);
}

/* Lie un fichier et renvoie le nombre d'octect lu */
int	ft_readfile(int fd, char **buffer)
{
	int	len;

	*buffer = malloc(PAGE_SIZE + 1);
	len = read(fd, *buffer, PAGE_SIZE);
	*(*buffer + PAGE_SIZE - (PAGE_SIZE - len)) = '\0';
	if (len < PAGE_SIZE)
	{
		close(fd);
		*buffer = ft_reallocstr(*buffer, len + 1);
		return (len);
	}
	return (dynamic_read(fd, len, buffer));
}

/* 
// Test unitaire, en quelque sorte
#include <stdio.h>
int main(int argc, char **argv)
{
	char *buffer;
	int size;

	if (argc > 1)
	{
		size = ft_readfile(argv[1], &buffer);
		printf("Buffer size: %d\n", size);
		size++;
		free(buffer);
	}
	return (0);
}
 */