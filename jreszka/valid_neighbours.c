/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_neighbours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:39:11 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/11 18:37:52 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_neighbours(char *buf, t_map map)
{
	int min_neighbours_nb;
	int i;

	min_neighbours_nb = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i - 1] == '#'
				|| buf[i + 1] == '#'
				|| buf[i - 5] == '#'
				|| buf[i + 5] == '#')
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
