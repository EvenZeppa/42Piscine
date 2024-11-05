/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:55:14 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 21:00:23 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/parser.h"
#include "../includes/validation.h"
#include "../includes/solver.h"
#include "../includes/print.h"
#include "../includes/square_engine.h"
#include <stdio.h>

/* int	handle_stdin(int fd)
{
	char		*buffer;
	int			buffer_size;
	int			fd;
	// t_map		*map;

	if (!fd)
	{
		fd = open(0, O_RDONLY);
		if (fd == -1)
			return (0);
	}
	buffer_size = ft_readfile(fd, &buffer);
	if (!check_meta_data(map, &buffer) || !*buffer)
	{
		if (!open())
		return (free(buffer), 1); // Erreur: Grid mal formatté
	}
	//solve(map, &buffer);
	free(buffer);
	return (0);
}
 */

int handle_arg(char *file, int fd)
{
	int			buffer_size;
	t_map		*map;
	char		*buffer;
	int			metadata_size;

	metadata_size = 0;
	if (!file)
		fd = 0;
	if (fd == -1)
		fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer_size = ft_readfile(fd, &buffer);
	// printf("Buffer Size : %d\n%s", buffer_size, buffer);
	map = init_map();
	if (!check_meta_data(map, &buffer, &metadata_size) || !*buffer)
	{
		if (buffer[buffer_size - 1] == '\n')
			buffer[--buffer_size] = '\0';
		fd = open(buffer, O_RDONLY);
		if (fd == -1)
			return (free(buffer), 1); // Erreur: Grid mal formatté
		handle_arg(buffer, fd);
	}
	else
	{
		solve(map, buffer, buffer_size);
		print_map(map, buffer, buffer_size);
		free(buffer - metadata_size - 1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		handle_arg(0, 0);
	i = 1;
	while (i < argc)
	{
		handle_arg(argv[i], -1);
		if (argc > 2 && i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);

	/* TEST EVEN */
	/* (void) argc;
	(void) argv;
	int			buffer_size;
	t_map		*map;
	char		*buffer;
	int			*range;
	int			line_size;
	int			metadata_size;

	metadata_size = 0;
	buffer_size = ft_readfile(open("grid100", O_RDONLY), &buffer);
	printf("Buffer Size : %d\n", buffer_size);
	map = init_map();
	if (!check_meta_data(map, &buffer, &metadata_size) || !*buffer)
		return (free(buffer), 1); // Erreur: Grid mal formatté

	range = malloc(sizeof(int) * 101);
	int	i;

	i = 0;
	while (i < 101)
		range[i++] = -1;
	line_size = range_gen(&buffer, map, &range);
	map->line_size = line_size;
	i = 0;
	printf("[");
	while (range[i] != -1)
		printf("%d, ", range[i++]);
	printf("]\n");

	square_build(map, range, range, 0);
	print_map_struct(map);
	buffer -= line_size;
	print_map_with_square(map, get_square_by_x_y(map, 69, 0), buffer, buffer_size - metadata_size - 1);
	free(buffer - metadata_size - 1);
	free_map(map);
	free(range);
	return (0); */
}

// ...................oo.........o...oo.............o....o....o.o......o.........o...o.o........o......

/* int	main(int argc, char *argv[])
{
	solve(&map, &buffer);
	// Imprimer le resultat
	// Free
	return (0);
} */
// ...........
// ...........
// .o.......o.
// ..oo.......
// .......o...
