/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:45:57 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/10 11:56:42 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place_tet(i, map)
{
	int available_places;
	int j;

	available_places = 0;
	j = 0;
	while (j < 4)
	{
		y = map.tets[i].hash[j].y - map.tets[i].ref_min.y;
		x = map.tets[i].hash[j].x - map.tets[i].ref_min.x;
		if (map.content[y].[x] == '.' )
			available_places++;
		j++;
	}
	if (available_places = 4)
		return (1);
	return (0);
}

int		can_move_tet_right(i, map)
{
	if (map.tets[i].width + map.tets[i].position.x <= map.size)
		return (1);
	return (0);
}
int 	can_move_tet_bottom(i, map)
{
	if (map.tets[i].height + map.tets[i].position.y <= map.size)
		return (1);
	return (0);
}

int		can_displace_tetri(i, map)
{
	if (can_move_tet_right(i, map) || can_move_tet_bottom(i, map))
		return (1);
	return (0);
}

int		first_tetri_can_be_displaced(map)
{
	return (can_displace_tetri(0, map));
}


void	ft_solve(t_map map, t_data data)
{
	while (map.placed_tetri_nb != (data.hash_nb / 4))
	{
		map.placed_tetri_nb = 0;
		while (first_tetri_can_be_displaced(map))
		{
			try_place_all_tetris(map);
		}
		map.size++;
	}
	ft_print_2d_table(map[0].content);
}
