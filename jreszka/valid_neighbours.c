#include "libft.h"
#include "fillit.h"

int valid_neighbours(char *buf, t_map map)
{
	int min_neighbours_nb;
	int i;
	
	min_neighbours_nb = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i-1] == '#'
				|| buf[i+1] == '#'
				|| buf[i-5] == '#'
				|| buf[i+5] == '#')
				min_neighbours_nb++;
		}
		i++;
	}
	if (min_neighbours_nb != map.hash_nb)
	{
		write(2, "error\n", 6);
		return (0);
	}
	return (1);
}