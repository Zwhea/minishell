/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:00:19 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/16 03:22:17 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:33:50 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/10 18:19:20 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		*(unsigned char *)(dst + i) = (unsigned char)c;
		i++;
	}
	return (dst);
}

void	*ft_memcset(void *dst, int c, int till, size_t max_ln)
{
	size_t	i;

	i = 0;
	while (i < max_ln && *(unsigned char *)(dst + i) != (unsigned char)till)
	{
		*(unsigned char *)(dst + i) = (unsigned char)c;
		i++;
	}
	return (dst);
}
