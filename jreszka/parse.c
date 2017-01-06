/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 10:02:52 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map parse(char *buf, t_map map)
{
	int		j;

	map.char_nb = 0;
	map.hash_nb = 0;
	map.dot_nb = 0;
	map.border_nl_nb = 0;
	map.between_nl_nb = 0;
	j = 1;
	while (buf[map.char_nb])
	{
		if (buf[map.char_nb] == '#')
			map.hash_nb++;
		if (buf[map.char_nb] == '.')
			map.dot_nb++;
		if ((j) % 5 == 0 && buf[map.char_nb] == '\n')
			map.border_nl_nb++;
		if ((map.char_nb + 1) % 21 == 0 && buf[map.char_nb] == '\n')
		{
			map.between_nl_nb++;
			j--;
		}
		map.char_nb++;
		j++;
	}
	return (map);
}
