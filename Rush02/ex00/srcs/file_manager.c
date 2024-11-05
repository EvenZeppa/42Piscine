/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:15:05 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:32 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/dict.h>
#include <../includes/ft.h>

char	*ft_realloc(char *buffer, int size)
{
	char	*buffer_tmp;

	buffer_tmp = malloc(size + 1);
	buffer_tmp = ft_strncat(buffer_tmp, buffer, size);
	free(buffer);
	return (buffer_tmp);
}

// Verifier qu'on n'est pas a la fin du fichier
char	*get_buffer_from_file(t_dict *dict)
{
	char	*buffer;
	char	*buffer_tmp;
	int		current_size;
	int		i;
	int		fd;

	fd = open(dict->selected_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer_tmp = malloc(BUFFER_SIZE);
	buffer = malloc(BUFFER_SIZE);
	current_size = BUFFER_SIZE;
	i = 1;
	while (current_size % BUFFER_SIZE == 0)
	{
		current_size = read(fd, buffer_tmp, BUFFER_SIZE);
		buffer = ft_realloc(buffer, i * BUFFER_SIZE + current_size);
		buffer = ft_strncat(buffer, buffer_tmp, current_size);
		i++;
	}
	close(fd);
	return (buffer);
}

/* char	*get_buffer_from_file(int fd)
{
    char *buffer;
    char *temp;
    char temp_buffer[BUFFER_SIZE];
    int bytes_read;
    int total_size = 0;
    int i;

    buffer = malloc(1);

    bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        temp = malloc(total_size + bytes_read + 1);

        i = 0;
        while (i < total_size)
        {
            temp[i] = buffer[i];
            i++;
        }

        i = 0;
        while (i < bytes_read)
        {
            temp[total_size + i] = temp_buffer[i];
            i++;
        }

        total_size += bytes_read;
        temp[total_size] = '\0';

        free(buffer);
        buffer = temp;

        bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
    }

    return buffer;
} */
