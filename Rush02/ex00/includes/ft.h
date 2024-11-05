/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:44:48 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:36:21 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define ARG_ERROR "Error\n"
# define DICT_ERROR "Dict Error\n"

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strncat(char *dest, char *src, int nb);
char	*ft_strcat(char *dest, char *src);
char	**ft_split(char *str, char *charset);
int		ft_isdigit(char c);
int		ft_isprint(char c);
char	*ft_strncpy(char *dest, char *src, int n);
int		is_charset(char *str, char *charset);
char	*ft_trim(char *str);
char	*ft_atoi_rules(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_swap(char *a, char *b);

#endif
