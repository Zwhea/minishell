/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:19:49 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/10 18:22:56 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *buf, int ch, size_t length)
{
	unsigned char	*dst;

	dst = buf;
	while (length && *dst != (unsigned char)ch)
	{
		dst++;
		length--;
	}
	if (!length)
		return ((void *)0);
	return ((void *)dst);
}
