/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_tetri_are_not_placed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:48:00 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 09:57:38 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int all_tetri_are_not_placed()
{
	if (number_of_letters(map.content) == map.tetri_nb)
		return (1);
	return (0);
}
