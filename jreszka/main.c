/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 10:12:57 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (num_are_valid(map[0]) && hash_neighbours_are_valid(buf, map[0]))
			ft_putstr("input file ok\n");
	}
	else
		write(2, "Usage: ./fillit input_file\n", 27);
	return (0);
}
