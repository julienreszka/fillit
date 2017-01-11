/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tets_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:58:13 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/11 18:48:14 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	ft_tets_chars(t_map map, t_data data)
{
	char	lettre;
	int		i;

	i = 0;
	lettre = 'A';
	while (i < data.hash_nb / 4)
	{
		map.tets[i].pos.x = 0;
		map.tets[i].pos.y = 0;
		map.tets[i].lettre = lettre;
		lettre++;
		i++;
	}
	return (map);
}
