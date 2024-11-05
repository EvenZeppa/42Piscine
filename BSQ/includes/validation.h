/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeel-qai <jeel-qai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:21:24 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/25 01:15:52 by jeel-qai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "map.h"

int	check_meta_data(t_map *map, char **buffer, int *read);

int	check_char(t_map *map, char c);
int	check_line_size(t_map *map, int line_size);
int	check_line_count(t_map *map, int y);

#endif
