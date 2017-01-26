/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:14:52 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/26 21:44:13 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Ecrit n 0 sur la chaine s sauf si n est 0 dans ce cas elle ne fait rien
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	tmp = s;
	while (n > 0)
	{
		*tmp++ = '\0';
		n--;
	}
}
