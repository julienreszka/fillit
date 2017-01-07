/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tets_ref_points.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:56:15 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/07 13:41:39 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map ft_init_hashs(t_map map)
{
	map.min_x = 4;
	map.min_y = 4;
	map.max_x = -1;
	map.max_y = -1;
	map.hash_i = -1;
	return (map);
}

t_map ft_tets_ref_points(t_map map, t_data data)
{
	map.tets_i = -1;
	while (++map.tets_i < (data.hash_nb / 4))
	{
		map = ft_init_hashs(map);
		while (++map.hash_i < 4)
		{
			if (map.tets[map.tets_i].hash[map.hash_i].x < map.min_x)
				map.min_x = map.tets[map.tets_i].hash[map.hash_i].x;
			if (map.tets[map.tets_i].hash[map.hash_i].y < map.min_y)
				map.min_y = map.tets[map.tets_i].hash[map.hash_i].y;
			if (map.tets[map.tets_i].hash[map.hash_i].x > map.max_x)
				map.max_x = map.tets[map.tets_i].hash[map.hash_i].x;
			if (map.tets[map.tets_i].hash[map.hash_i].y > map.max_y)
				map.max_y = map.tets[map.tets_i].hash[map.hash_i].y;
		}
		map.tets[map.tets_i].ref_min.x = map.min_x;
		map.tets[map.tets_i].ref_min.y = map.min_y;
		map.tets[map.tets_i].ref_max.x = map.max_x;
		map.tets[map.tets_i].ref_max.y = map.max_y;
		map.tets[map.tets_i].largeur = map.max_x - map.min_x;
		map.tets[map.tets_i].hauteur = map.max_y - map.min_y;
		printf("\nmin_x %d\nmin_y %d\nmax_x %d\nmax_y %d",
			map.tets[map.tets_i].ref_min.x,
			map.tets[map.tets_i].ref_min.y,
			map.tets[map.tets_i].ref_max.x,
			map.tets[map.tets_i].ref_max.y
			);
		printf("\nlargeur %d\nhauteur %d\n",
			map.tets[map.tets_i].largeur,
			map.tets[map.tets_i].hauteur
			);
	}
	return (map);
}