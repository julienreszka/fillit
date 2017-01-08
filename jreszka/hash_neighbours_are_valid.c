/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_neighbours_are_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:00:34 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/08 16:19:21 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_hash(char *buf, t_data data, int i, int neighbours_nb)
{
	if (buf[i - 1] == '#' && i > 1)
		neighbours_nb++;
	if (buf[i + 1] == '#' && i < (data.char_nb - 1))
		neighbours_nb++;
	if (buf[i - 5] == '#' && i > 4)
		neighbours_nb++;
	if (buf[i + 5] == '#' && i < (data.char_nb - 5))
		neighbours_nb++;
	return (neighbours_nb);
}

int		hash_neighbours_are_valid(char *buf, t_data data)
{
	int neighbours_nb;
	int hash_i;
	int i;

	neighbours_nb = 0;
	hash_i = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			neighbours_nb = check_hash(buf, data, i, neighbours_nb);
			hash_i++;
		}
		if ((hash_i + 1) % 4 == 0)
		{
			if (neighbours_nb != 6 || neighbours_nb != 8)
				write(2, "error\n", 6);
			if (neighbours_nb != 6 || neighbours_nb != 8)
				return (0);
			neighbours_nb = 0;
			hash_i = 0;
		}
	}
	return (1);
}
