/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:24 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/24 05:47:49 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:13 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/09 15:03:19 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (1)
	{
		if (*tmp == c)
			return (tmp);
		if (!*tmp)
			return (NULL);
		tmp++;
	}
	return (NULL);
}

size_t	ft_index_of(const char *s, int c)
{
	char	*res;

	res = ft_strchr(s, c);
	if (res == NULL)
		return (-1);
	return (res - s);
}
