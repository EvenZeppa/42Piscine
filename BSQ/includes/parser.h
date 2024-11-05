/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeel-qai <jeel-qai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:20:05 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/24 19:00:26 by jeel-qai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define PAGE_SIZE 1003520
# define BUFFER_MULT 2

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_reallocstr(char *ptr, size_t size);
int		ft_readfile(int fd, char **buffer);

#endif
