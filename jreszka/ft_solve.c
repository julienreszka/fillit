/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:45:57 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/11 18:30:54 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place_tet(int i, t_map map, int pos_x, int pos_y)
{
	int available_places;
	int j;
	int x;
	int y;

	available_places = 0;
	j = 0;
	while (j < 4)
	{
		y = pos_y + map.tets[i].hash[j].y - map.tets[i].ref_min.y;
		x = pos_x + map.tets[i].hash[j].x - map.tets[i].ref_min.x;
		if (x < map.size && y < map.size)
		{
			if (map.content[y][x] == '.')
				available_places++;
		}
		j++;
	}
	if (available_places == 4)
		return (1);
	return (0);
}

void	place_tet(int i, t_map map, int pos_x, int pos_y)
{
	int j;
	int x;
	int y;

	j = 0;
	while (j < 4)
	{
		y = pos_y + map.tets[i].hash[j].y - map.tets[i].ref_min.y;
		x = pos_x + map.tets[i].hash[j].x - map.tets[i].ref_min.x;
		map.content[y][x] = map.tets[i].lettre;
		j++;
	}
}

int		can_move_tet_right(int i, t_map map)
{
	if (map.tets[i].width + map.tets[i].pos.x < map.size)
		return (1);
	return (0);
}

int		can_move_tet_bottom(int i, t_map map)
{
	if (map.tets[i].height + map.tets[i].pos.y < map.size)
	{
		return (1);
	}
	return (0);
}

int		can_displace_tetri(int i, t_map map)
{
	if (can_move_tet_right(i, map)
		|| can_move_tet_bottom(i, map))
	{
		return (1);
	}
	return (0);
}

int		first_tetri_can_be_displaced(t_map map)
{
	return (can_displace_tetri(0, map));
}

t_map	init_tets_pos(t_map map, t_data data)
{
	int i;

	i = 0;
	while (i < (data.hash_nb / 4))
	{
		map.tets[i].pos.x = 0;
		map.tets[i].pos.y = 0;
		i++;
	}
	return (map);
}

t_map	rm_tet(int i, t_map map)
{
	map.pos.y = 0;
	while (map.pos.y < map.size)
	{
		map.pos.x = 0;
		while (map.pos.x < map.size)
		{
			if (map.content[map.pos.y][map.pos.x] == map.tets[i].lettre)
				map.content[map.pos.y][map.pos.x] = '.';
			map.pos.x++;
		}
		map.pos.y++;
	}
	return (map);
}

int		is_placed_tet(int i, t_map map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map.size)
	{
		while (x < map.size)
		{
			if (can_place_tet(i, map, map.tets[i].pos.x, map.tets[i].pos.y))
			{
				place_tet(i, map, map.tets[i].pos.x, map.tets[i].pos.y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	move_tet_pos(int i, t_map map)
{
	if (map.tets[i].pos.x + map.tets[i].width < map.size)
	{
		map.tets[i].pos.x++;
	}
	else
	{
		map.tets[i].pos.x = 0;
		map.tets[i].pos.y++;
	}
	return (map);
}

/*
**	ft_print_2d_table(map.content);
**	ft_putstr("\n");
**	sleep(1);
*/

t_map	try_place_all_tets(t_map map)
{
	if (is_placed_tet(map.placed_tets_nb, map))
	{
		map.placed_tets_nb++;
	}
	else if (map.tets[map.placed_tets_nb].pos.y < map.size
		&& map.tets[map.placed_tets_nb].pos.x < map.size)
	{
		map = move_tet_pos(map.placed_tets_nb, map);
	}
	else
	{
		map.tets[map.placed_tets_nb].pos.y = 0;
		map.tets[map.placed_tets_nb].pos.x = 0;
		map.placed_tets_nb--;
		map = rm_tet(map.placed_tets_nb, map);
		map = move_tet_pos(map.placed_tets_nb, map);
	}
	return (map);
}

int		ft_solve(t_map map, t_data data)
{
	while (map.placed_tets_nb != (data.hash_nb / 4))
	{
		map = init_tets_pos(map, data);
		while (first_tetri_can_be_displaced(map))
		{
			if (map.placed_tets_nb == (data.hash_nb / 4))
			{
				ft_print_2d_table(map.content);
				return (0);
			}
			map = try_place_all_tets(map);
		}
		map.size++;
		map = make_map_bigger(map);
	}
	return (0);
}
