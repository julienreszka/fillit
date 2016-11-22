#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


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

int		ft_floor_sqrt(int nb)
{
	int		i;
	int		icarre;
	int		distance;
	int		distance_precedente;

	i = 2;
	distance_precedente = nb * 2;
	while (i <= nb)
	{
		icarre = i * i;
		distance = nb - icarre;
		if (distance <= 0)
			return (i);
		printf("distance %d\n", distance);
		if (distance_precedente >= distance)
			distance_precedente = distance;
		i++;
	}
	return (0);
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
	//printf("fd is %d\n", fd);
	//fd = -1;
	if (fd == -1)
	{
		write(2, "open() failed\n", 14);
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	//printf("ret is %d\n", ret);
	//ret = -1;
	if (ret == -1)
	{
		write(2, "read() failed\n", 14);
		return (0);
	}
	buf[ret] = '\0';
	//printf("buf below\n%s\n", buf);
	if (close(fd) == -1)
	{
		write(2, "close() failed\n", 15);
		return (0);
	}
/*
**	Afficher "error" si
**		le nombre de characteres est impossible
**		le nombre de # est impossible
**		le nombre de . est impossible
**		les \n ne sont pas au bon endroit
*/
	int		char_nb;
	int		hash_nb;
	int		dot_nb;
	int		border_nl_nb;
	int		between_nl_Nb;
	int		i;
	int		j;
	int		tetriminos_nb;

	char_nb = 0;
	hash_nb = 0;
	dot_nb = 0;
	border_nl_nb = 0;
	between_nl_Nb = 0;
	i = 0;
	j = 1;
	tetriminos_nb = 0;
	while (buf[i])
	{
		char_nb++;
		if (buf[i] == '#')
			hash_nb++;
		if (buf[i] == '.')
			dot_nb++;
		if ((j) % 5 == 0 && buf[i] == '\n')
			border_nl_nb++;
		if ((i + 1) % 21 == 0 && buf[i] == '\n')
		{
			between_nl_Nb++;
			j--;
		}
		i++;
		j++;
	}
	printf("char_nb\t%d\nhash_nb\t%d\ndot_nb\t%d\n", char_nb, hash_nb, dot_nb);
	printf("border_nl_nb\t%d\nbetween_nl_Nb \t%d\n", border_nl_nb, between_nl_Nb);
	if (char_nb < MIN_CHAR_NB || char_nb > MAX_CHAR_NB)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if ((char_nb + 1) % (20 + 1) != 0)
	{
		write(2, "error\n", 6);
		return (0);
	}
	tetriminos_nb = (char_nb + 1) / 21;
	printf("tetriminos_nb\t%d\n", tetriminos_nb);
	if (hash_nb / tetriminos_nb != NORMAL_HASH_NB)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if (dot_nb / tetriminos_nb != NORMAL_DOT_NB)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if (border_nl_nb / tetriminos_nb != 4)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if ((between_nl_Nb + 1) / tetriminos_nb != 1)
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
**	Transformer les 4 premiers # en A les 4 suivants en B et ainsi de suite
*/

	/*
		i = 0;
		char le_char = 'A';
		while (buf[i])
		{
			if (buf[i] == '#')
				buf[i] = le_char;
			if (i !=0 && (i+1) % 21 == 0)
				le_char++;
			i++;
		}
		printf("%s\n", buf);
	*/

/*
**	Verifier recursivement s'il est possible de poser tous les tetrimino dans le carre minimal l'augmenter juqu'a ce que ca fonctionne.
**	Afficher le carre resolu
*/

/*
**	Afficher le carre resolu et optimise
*/

	return (0);
}
