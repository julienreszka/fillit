#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define BUF_SIZE 4096
# define NORMAL_DOT_NB 12
# define NORMAL_HASH_NB 4
# define MIN_CHAR_NB 20
# define MAX_CHAR_NB 545

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetrimino
{
	t_point ref_min;
	t_point ref_max;
	t_point hash[4];
	char lettre;
	int largeur;
	int hauteur;
}				t_tetrimino;

typedef struct	s_map
{
	int char_nb;
	int hash_nb;
	int dot_nb;
	int border_nl_nb;
	int between_nl_nb;
	int tetriminos_nb;
	int size;
	char **content;
	t_point p_i;
}				t_map;

char			*get_buf(char *file_name);
t_map 			parse(char *buf, t_map map);
int				num_are_valid(t_map map);
int				hash_neighbours_are_valid(char *buf, t_map map);

#endif