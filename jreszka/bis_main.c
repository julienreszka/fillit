#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_map map[1];
		char *buf;
	
		buf = get_buf(argv[1]);
		map[0] = parse(buf, map[0]);
		if (validate(map[0]) && valid_neighbours(buf, map[0]))
			puts("ok");
	}
	else
		write(2, "Usage: ./fillit input_file\n", 27);
	return (0);
}