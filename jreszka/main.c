#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 4096
#define NORMAL_DOT_NB 12
#define NORMAL_HASH_NB 4
#define MIN_CHAR_NB 20
#define MAX_CHAR_NB 545

/*
** Ci dessous a virer une fois fini
*/

#include <stdio.h>

/*
** Ci dessus a virer une fois fini
*/


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
	int size;
	char **content;
	t_point p_i;
}				t_map;

int		ft_floor_sqrt(int nb)
{
	int i;

	i = 2;	
	while (i * i <= nb)
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*buf;
/*
**	Verifier si le nombre d'arguments est 2
*/
	if (argc != 2)
	{
		write(2, "Usage: ./fillit input_file\n", 27);
		return (0);
	}
/*
**	Ouvrir le fichier, le lire, le mettre dans un buffer puis fermer le fichier
*/
	buf = (char *)malloc(sizeof(char) * 10000);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "open() failed\n", 14);
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		write(2, "read() failed\n", 14);
		return (0);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		write(2, "close() failed\n", 15);
		return (0);
	}

/*
**	Parser le buffer et recuperer les datas necessaires aux checks
*/

	int		char_nb;
	int		hash_nb;
	int		dot_nb;
	int		border_nl_nb;
	int		between_nl_nb;
	int		j;


	char_nb = 0;
	hash_nb = 0;
	dot_nb = 0;
	border_nl_nb = 0;
	between_nl_nb = 0;
	j = 1;
	while (buf[char_nb])
	{
		if (buf[char_nb] == '#')
			hash_nb++;
		if (buf[char_nb] == '.')
			dot_nb++;
		if ((j) % 5 == 0 && buf[char_nb] == '\n')
			border_nl_nb++;
		if ((char_nb + 1) % 21 == 0 && buf[char_nb] == '\n')
		{
			between_nl_nb++;
			j--;
		}
		char_nb++;
		j++;
	}

/*
**	Afficher "error" si
**		le nombre de characteres est impossible
**		le nombre de # est impossible
**		le nombre de . est impossible
**		les \n ne sont pas au bon endroit
*/

	int		tetriminos_nb;
	tetriminos_nb = (char_nb + 1) / 21;
	if (char_nb < MIN_CHAR_NB
		|| char_nb > MAX_CHAR_NB
		|| (char_nb + 1) % (20 + 1) != 0
		|| (hash_nb / tetriminos_nb != NORMAL_HASH_NB)
		|| (dot_nb / tetriminos_nb != NORMAL_DOT_NB)
		|| (border_nl_nb / tetriminos_nb != 4)
		|| ((between_nl_nb + 1) / tetriminos_nb != 1))
	{
		write(2, "error\n", 6);
		return (0);
	}

/*
**	Verifier que les # ont tous au moin un voisin sinon retourner error
*/

	int nb_voisin_min;
	int index;
	
	nb_voisin_min = 0;
	index = 0;
	while (buf[index])
	{
		if (buf[index] == '#')
		{
			if (buf[index-1] == '#'
				|| buf[index+1] == '#'
				|| buf[index-5] == '#'
				|| buf[index+5] == '#')
			{
				nb_voisin_min++;
			}
		}
		index++;
	}
	if (nb_voisin_min != hash_nb)
	{
		write(2, "error\n", 6);
		return (0);
	}

/*
**	En fonction du nombre de # du fichier de base calculer la taille minimale du nombre de caracteres du carre
*/
	int 	min_square_space;

	min_square_space = ft_floor_sqrt(hash_nb);
	printf("min_square_space\t%d\n", min_square_space);

/*
**	Decomposer le buffer en un tableau en 2D
*/

	char **tetris_table;
	tetris_table = ft_strsplit(buf, '\n');

/*
**	Recuperation des coordonnees des # dans une structure de tetrimino
*/

	t_tetrimino tetrimino[tetriminos_nb];

	int line;
	int ka;
	int tetris_iter;
	int hash_iter;

	line = 0;
	tetris_iter = -1;
	while (line < tetriminos_nb * 4)
	{
		if ((line % 4) == 0)
		{
			tetris_iter++;
			hash_iter = 0;
		}
		ka = 0;
		while (tetris_table[line][ka])
		{
			if (tetris_table[line][ka] == '#')
			{
				tetrimino[tetris_iter].hash[hash_iter].x = ka % 4;
				tetrimino[tetris_iter].hash[hash_iter].y = line % 4;
				hash_iter++;
			}
			ka++;
		}
		line++;
	}

/*
**	Recuperation du point de reference de chaque tetrimino
*/

	int min_x;
	int min_y;
	int max_x;
	int max_y;

	tetris_iter = 0;
	while (tetris_iter < tetriminos_nb)
	{
		hash_iter = 0;
		min_x = 4;
		min_y = 4;
		max_x = 0;
		max_y = 0;
		while (hash_iter < 4)
		{
			if (tetrimino[tetris_iter].hash[hash_iter].x < min_x)
				min_x = tetrimino[tetris_iter].hash[hash_iter].x;
			if (tetrimino[tetris_iter].hash[hash_iter].y < min_y)
				min_y = tetrimino[tetris_iter].hash[hash_iter].y;
			if (tetrimino[tetris_iter].hash[hash_iter].x > max_x)
				max_x = tetrimino[tetris_iter].hash[hash_iter].x;
			if (tetrimino[tetris_iter].hash[hash_iter].y > max_y)
				max_y = tetrimino[tetris_iter].hash[hash_iter].y;
			hash_iter++;
		}
		tetrimino[tetris_iter].ref_min.x = min_x;
		tetrimino[tetris_iter].ref_min.y = min_y;
		tetrimino[tetris_iter].ref_max.x = max_x;
		tetrimino[tetris_iter].ref_max.y = max_y;
		tetrimino[tetris_iter].largeur = max_x - min_x;
		tetrimino[tetris_iter].hauteur = max_y - min_y;
		printf("\nmin_x %d\nmin_y %d\nmax_x %d\nmax_y %d",
			tetrimino[tetris_iter].ref_min.x,
			tetrimino[tetris_iter].ref_min.y,
			tetrimino[tetris_iter].ref_max.x,
			tetrimino[tetris_iter].ref_max.y
			);
		printf("\nlargeur %d\nhauteur %d\n",
			tetrimino[tetris_iter].largeur,
			tetrimino[tetris_iter].hauteur
			);
		tetris_iter++;
	}

/*
**	Assigner la lettre de chaque tetrimino
*/

	tetris_iter = 0;
	char charact = 'A';
	while (tetris_iter < tetriminos_nb)
	{
		tetrimino[tetris_iter].lettre = charact + tetris_iter;
		printf("\n%c\n", tetrimino[tetris_iter].lettre);
		tetris_iter++;
	}

/*
**	Initialisation carre minimal
*/



	char **map;
	map = (char**)malloc(sizeof(char*) * (min_square_space + 1));
	int hauteur;
	hauteur = 0;
	int indexe;
	while(hauteur < min_square_space)
	{
		map[hauteur] = (char*)malloc(sizeof(char) * (min_square_space + 1));
		indexe = 0;
		while (indexe < min_square_space)
		{
			map[hauteur][indexe] = '.';
			indexe++;
		}
		map[hauteur][indexe] = '\0';
		hauteur++;
	}
	map[hauteur] = 0;


/*
**	On verifie si on peut placer un tetrimino sur la map
**		S'il n'y a rien sur la map en dessous du tetrimino
**		Si le tetrimino rentre dans la map en largeur et hauteur
*/

	t_map carte;
	
	carte.size = min_square_space;

	tetris_iter = 0;
	while(tetris_iter < tetriminos_nb)
	{
		carte.p_i.x = 0;
		carte.p_i.y = 0;
		hash_iter = 0;
		while(hash_iter < 4)
		{
			if (map[tetrimino[tetris_iter].hash[hash_iter].y
				- tetrimino[tetris_iter].ref_min.y 
				+ carte.p_i.y][tetrimino[tetris_iter].hash[hash_iter].x
				- tetrimino[tetris_iter].ref_min.x
				+ carte.p_i.x] == '.')
			{
				printf("t%d#%d\t", tetris_iter, hash_iter);
				puts("il y a de la place");
				printf("x\t%d y\t%d\n", carte.p_i.x, carte.p_i.y);

				map[tetrimino[tetris_iter].hash[hash_iter].y
					- tetrimino[tetris_iter].ref_min.y
					+ carte.p_i.y][tetrimino[tetris_iter].hash[hash_iter].x
					- tetrimino[tetris_iter].ref_min.x
					+ carte.p_i.x] = tetrimino[tetris_iter].lettre;
			}
			else
			{
				printf("t%d#%d\t", tetris_iter, hash_iter);
				puts("pas de place");
				printf("x\t%d y\t%d\n", carte.p_i.x, carte.p_i.y);
				if (carte.p_i.y < carte.size)
				{	
					if (carte.p_i.x < carte.size)
					{
						puts("Point deja pris");
						carte.p_i.x++;

					}
					else if (carte.p_i.x == carte.size)
					{
						puts("Ligne deja prise");
						carte.p_i.y++;
						carte.p_i.x = 0;
					}
					hash_iter = -1;
				}
			}
			hash_iter++;
		}
		tetris_iter++;
	}


	printf("\n");
	while(*map)
	{
		printf("%s\n", *map);
		map++;
	}


/*
**	Verifier recursivement s'il est possible de poser tous les tetrimino dans le carre minimal l'augmenter juqu'a ce que ca fonctionne.
**	Afficher le carre resolu
*/

/*
**	Afficher le carre resolu et optimise
*/

	return (0);
}