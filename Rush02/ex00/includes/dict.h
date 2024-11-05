/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:44:48 by ezeppa            #+#    #+#             */
/*   Updated: 2024/09/22 23:13:57 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# define DICT_PATH "./base_en.dict"
# define BUFFER_SIZE 4096

# define MAX_INPUT_SIZE 100
# define GROUP_SIZE 3

# include <fcntl.h>

struct	s_key_value_pair;

typedef struct s_key_value_pair
{
	char					*key;
	char					*value;
	struct s_key_value_pair	*next;
}	t_key_value_pair;

typedef struct s_dict
{
	char				*selected_path;
	t_key_value_pair	*first;
}	t_dict;

t_dict				*initialize_s_dict(void);
void				insertion_s_dict(t_dict *dict, char *key, char *value);
t_key_value_pair	*get_dict_elem_by_key(t_dict *dict, char *key);
void				print_s_dict(t_dict *dict);

void				parse_dict(t_dict *s_dict, int is_base);
char				*get_buffer_from_file(t_dict *s_dict);

char				**get_ones_array(t_dict *dict);
char				**get_tens_array(t_dict *dict);
char				**get_units_array(t_dict *dict);
char				**get_group_units_array(t_dict *dict);

#endif
