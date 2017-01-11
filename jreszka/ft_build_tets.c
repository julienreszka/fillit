/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:06:49 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/11 18:35:03 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map ft_build_tets(char **table, t_map map, t_data data)
{
	while (table[++map.table_i])
	{
		map.charac_i = -1;
		while (table[map.table_i][++map.charac_i])
		{
			if (table[map.table_i][map.charac_i] == '#')
			{

				map.tets[map.tets_i].hash[map.hash_i].x = map.charac_i;
				map.tets[map.tets_i].hash[map.hash_i].y = (map.table_i % 4);
				map.hash_i++;
			}
		}
		if ((map.table_i + 1) % 4 == 0)
		{
			map.tets_i++;
			map.hash_i = 0;
		}
	}
	int i;
	int j;

	i = 0;
	while (i < (data.hash_nb /4))
	{
		j = 0;
		while (j < 4)
		{
			j++;
		}
		i++;
	}
	map = ft_tets_ref_points(map, data);
	return (map);
}
