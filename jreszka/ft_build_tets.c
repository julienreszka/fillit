/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:06:49 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 22:06:49 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map ft_build_tets(char **table, t_map *map)
{
	int table_i;
	int tets_i;
	int charac_i;
	int hash_i;

	table_i = -1;
	tets_i = 0;
	hash_i = 0;
	while (table[++table_i])
	{
		if ((table_i + 1) % 4 == 0)
		{
			tets_i++;
			hash_i = 0;
		}
		charac_i = -1;
		while (table[table_i][++charac_i])
		{
			if (table[table_i][charac_i] == '#')
			{

				map.tets[tets_i].hash[hash_i].x = charac_i;
				map.tets[tets_i].hash[hash_i].y = (table_i % 4);
				hash_i++;
			}
		}
	}
	return (map);
}
