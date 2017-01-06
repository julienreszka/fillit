/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2d_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:35:26 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/06 19:37:42 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_print_2d_table(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putstr(str[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putchar('\n');
}
