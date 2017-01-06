/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2d_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:35:26 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 12:18:54 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_print_2d_table(char **str)
{
	int i;
	while (str[i] != 0)
	{
		ft_putstr(str[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putchar('\n');
}
