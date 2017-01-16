/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/16 16:49:36 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		main(int argc, char **argv)
{
	char	*buf;
	t_data	data[1];
	t_map	map[1];

	if (argc == 2)
	{
		buf = get_buf(argv[1]);
		data[0] = parse(buf, data[0]);
		if (num_are_valid(data[0]) && hash_neighbours_are_valid(buf, data[0]))
		{
			map[0] = ft_init_map(map[0], data[0]);
			map[0] = ft_build_tets(ft_strsplit(buf, '\n'), map[0], data[0]);
			ft_solve(map[0], data[0]);
		}
	}
	else
		write(1, "Usage: ./fillit input_file\n", 27);
	return (0);
}
