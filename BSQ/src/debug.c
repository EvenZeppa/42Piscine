/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:01:53 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 15:14:51 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/debug.h"

t_square	**init_squares_tab(int size)
{
	t_square **squares;

	squares = malloc(sizeof(t_square) * size + 1);
	squares[size + 1] = 0;
	return (squares);
}

/* Affiche la map en y ajoutant le carre donne */
void	print_map_with_squares(
	t_map *map, t_square **squares, char *buffer, int size_buffer)
{
	int	i;
	int	x;
	int	y;

	if (*squares)
	{
		i = 0;
		while (squares[i])
		{
			y = squares[i]->y;
			while (y < (squares[i]->y + squares[i]->size))
			{
				x = squares[i]->x;
				while (x < (squares[i]->x + squares[i]->size))
				{
					buffer[coord_to_index(x, y, map->line_size + 1)] = map->full;
					x++;
				}
				y++;
			}
		}
	}
	write(1, buffer, size_buffer);
}

/* Affiche l'ensemble des informations de la map */
void	print_map_struct(t_map *map)
{
	t_square	*current;
	int			i;

	if (!map)
		return ;
	printf("----- MAP VALUES -----\n");
	printf("Nbr Line: %d\nEmpty: %c\nWall: %c\nFull: %c\nLine Size: %d\n",
		map->nbr_line, map->empty, map->wall, map->full, map->line_size);
	printf("X Max: %d\nY Max: %d\nSize Max: %d\n",
		map->x_max, map->y_max, map->size_max);
	current = map->first;
	i = 0;
	while (current->next)
	{
		printf("----- SQUARE VALUES %d -----\n", i++);
		printf("X: %d\nY: %d\nSize: %d\nInitial Size: %d\n",
			current->x, current->y, current->size, current->initial_size);
		current = current->next;
	}
	return ;
}

/* Retourne le carre en fonction de x et y, sinon NULL */
t_square	*get_square_by_x_y(t_map *map, int x, int y)
{
	t_square	*square;

	square = map->first;
	while (square->next && square->next->next)
	{
		if (square->x == x && square->y == y)
			return (square);
		square = square->next;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	char		*buffer;
	int			buffer_size;
	t_map		*map;
	t_square	**squares;
	int			metadata_size;
	int			*range;
	int			*range_mask;
	t_square	*current_square;
	int			i;
	int			y;
	char		*user_text;

	buffer_size = ft_readfile(open("grid100", O_RDONLY), &buffer);

	map = init_map();
	squares = init_squares_tab(1000);

	if (!check_meta_data(map, &buffer, &metadata_size) || !*buffer)
		return (free(buffer), 1); // Erreur: Grid mal formatté

	malloc_ranges(buffer, &range, &range_mask);

	if (!range_gen(&buffer, map, &range))
		return (1);
	buffer -= map->line_size;

	i = 0;
	y = 1;
	while (y < map->nbr_line)
	{
		scanf("%p", &user_text);
		if (ft_strcmp(user_text, "m") == 0)
			print_map_struct(map);
		else if (ft_strcmp(user_text, "bs") == 0)
			printf("Buffer size : %d\n", buffer_size);
		else if (ft_strcmp(user_text, "r") == 0)
		{
			int k = 0;
			printf("Range : [");
			while (range[k] != -1)
			{
				printf("%d", range[k++]);
				if (range[k + 1] != -1)
					printf(", ");
			}
			printf("]\n");
		}
		else if (ft_strcmp(user_text, "rm") == 0)
		{
			int k = 0;
			printf("Range mask : [");
			while (range_mask[k] != -1)
			{
				printf("%d", range_mask[k++]);
				if (range_mask[k + 1] != -1)
					printf(", ");
			}
			printf("]\n");
		}
		else if (atoi(user_text) > 0)
			y += atoi(user_text);
		else
			continue;

		while (i >= 0)
			squares[i--] = NULL;
		solve(map, buffer, (y * map->line_size));

		current_square = map->first;
		while (current_square->next->next)
		{
			squares[i] = current_square;
			current_square = current_square->next;
			i++;
		}
		print_map_with_squares(map, squares, buffer, (y * map->line_size));
	}

	return (0);
	/* int			buffer_size;
	t_map		*map;
	char		*buffer;
	int			*range;
	int			line_size;
	int			metadata_size;
	t_square	**squares;

	metadata_size = 0;
	buffer_size = ft_readfile(open("grid100", O_RDONLY), &buffer);
	printf("Buffer Size : %d\n", buffer_size);
	map = init_map();
	squares = init_squares_tab(1000);
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
	print_map_with_squares(map, squares, buffer, buffer_size - metadata_size - 1);
	free(buffer - metadata_size - 1);
	free_map(map);
	free(range);
	return (0); */
}
