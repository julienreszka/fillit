#include "libft.h"
#include "fillit.h"

int	validate(t_map map)
{
	map.tetriminos_nb = (map.char_nb + 1) / 21;
	if (map.char_nb < MIN_CHAR_NB
		|| map.char_nb > MAX_CHAR_NB
		|| (map.char_nb + 1) % (20 + 1) != 0
		|| (map.hash_nb / map.tetriminos_nb != NORMAL_HASH_NB)
		|| (map.dot_nb / map.tetriminos_nb != NORMAL_DOT_NB)
		|| (map.border_nl_nb / map.tetriminos_nb != 4)
		|| ((map.between_nl_nb + 1) / map.tetriminos_nb != 1))
	{
		write(2, "error\n", 6);
		return (0);
	}
	return (1);
}