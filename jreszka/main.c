/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/10 22:26:27 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *buf;
		t_data data[1];
		t_map map[1];

		buf = get_buf(argv[1]);
		data[0] = parse(buf, data[0]);
		if (num_are_valid(data[0]) && hash_neighbours_are_valid(buf, data[0]))
		{
			map[0] = ft_init_map(map[0], data[0]);
			//ft_print_2d_table(map[0].content);
			map[0] = ft_build_tets(ft_strsplit(buf, '\n'), map[0], data[0]);
			ft_solve(map[0], data[0]);
		}
	}
	else
		write(2, "Usage: ./fillit input_file\n", 27);
	return (0);
}
