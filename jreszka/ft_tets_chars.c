/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tets_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:58:13 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/08 17:02:13 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	ft_tets_chars(t_map map, t_data data)
{
	char lettre;
	int i;

	i = 0;
	lettre = 'A';
	while (i < data.hash_nb / 4)
	{
		map.tets[i].lettre = lettre;
		printf("%c\n", map.tets[i].lettre);
		lettre++;
		i++;
	}
	return (map);
}