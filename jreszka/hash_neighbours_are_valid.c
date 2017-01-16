/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_neighbours_are_valid.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:00:34 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/16 17:29:47 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_data		check_hash(char *buf, t_data data, int i)
{
	
	if (buf[i - 1] == '#' && (i >= (data.tetri_i - 1) * 20 + data.tetri_i))
	{
		// ft_putstr("# a Gauche \n");
		data.neighbours_nb++;
	}
	if (buf[i + 1] == '#' && i < (data.tetri_i * 20 + data.tetri_i - 2))
	{
		// ft_putstr("# a Droite \n");
		data.neighbours_nb++;
	}
	if (buf[i - 5] == '#' && i > ((data.tetri_i - 1) * 20 + data.tetri_i + 3))
	{
		// ft_putstr("# en Haut \n");
		data.neighbours_nb++;
	}
	if (buf[i + 5] == '#' && i < (data.tetri_i * 20 + data.tetri_i - 6))
	{
		// ft_putstr("# en Bas\n");
		data.neighbours_nb++;
	}
	return (data);
}

int		hash_neighbours_are_valid(char *buf, t_data data)
{
	int i;

	data.neighbours_nb = 0;
	data.tetri_i = 1;
	data.hash_i = 0;
	i = -1;
	while (buf[++i])
	{
		// ft_putstr("i :");
		// ft_putnbr(i);
		// ft_putstr("\n");
		if (buf[i] == '#')
		{
			// ft_putstr("Il trouve un # \n");
			data.hash_i++;
			data = check_hash(buf, data, i);
		}
		if (data.hash_i == 4)
		{
			data.tetri_i++;
			// ft_putstr("data neighbours_nb");
			// ft_putnbr(data.neighbours_nb);
			// ft_putstr("\n");
			if (data.neighbours_nb != 6 && data.neighbours_nb != 8)
				write(1, "error\n", 6);
			if (data.neighbours_nb != 6 && data.neighbours_nb != 8)
				return (0);
			data.neighbours_nb = 0;
			data.hash_i = 0;
		}
	}
	return (1);
}
