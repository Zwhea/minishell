/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:57:35 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/11 13:03:36 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	len_base;

	i = 0;
	k = 0;
	while (i < size && dst[i])
		i++;
	if (i + 1 > size)
		return (size + ft_strlen(src));
	len_base = i;
	while (size > i + 1 && k < ft_strlen(src))
		dst[i++] = src [k++];
	if (i < size)
		dst[i] = 0;
	return (len_base + ft_strlen(src));
}
