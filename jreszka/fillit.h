/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:47:23 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 22:04:14 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

#include <stdio.h>

# define BUF_SIZE 4096
# define NORMAL_DOT_NB 12
# define NORMAL_HASH_NB 4
# define MIN_CHAR_NB 20
# define MAX_CHAR_NB 545

typedef struct	s_data
{
	int char_nb;
	int hash_nb;
	int dot_nb;
	int border_nl_nb;
	int between_nl_nb;
	int tetri_nb;

}				t_data;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tet
{
	t_point ref_min;
	t_point ref_max;
	t_point hash[4];
	char lettre;
	int largeur;
	int hauteur;
}				t_tet;

typedef struct	s_map
{
	int size;
	char **content;
	t_tet *tets;
}				t_map;

char			*get_buf(char *file_name);
t_data 			parse(char *buf, t_data data);
int				num_are_valid(t_data data);
int				hash_neighbours_are_valid(char *buf, t_data data);
void			ft_print_2d_table(char **str);
int				ft_int_sqrt(int nb);
t_map			ft_init_map(t_map map, t_data data);
void			ft_build_tets(char **table, t_map *map);

#endif
