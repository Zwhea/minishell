/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:47 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/01/05 17:40:51 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(char *a, char *b, char *c)
{
	int		ln;
	char	*dst;
	int		i;

	ln = ft_strlen(a) + ft_strlen(b) + ft_strlen(c) + 1;
	dst = malloc(ln);
	if (!dst)
		return (NULL);
	ln = 0;
	i = 0;
	while (a[i])
		dst[ln++] = a[i++];
	i = 0;
	while (b[i])
		dst[ln++] = b[i++];
	i = 0;
	while (c[i])
		dst[ln++] = c[i++];
	dst[ln++] = c[i++];
	return (dst);
}
