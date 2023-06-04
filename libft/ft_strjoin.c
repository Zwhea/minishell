/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:33 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/01/09 17:49:22 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*tmp;

	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	tmp = dst;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	return (dst);
}

char	*ft_strjoin_free_sec_sf(char *s1, char *s2)
{
	char	*dst;

	if (s2 == NULL)
		return (NULL);
	dst = ft_strjoin(s1, s2);
	free(s2);
	return (dst);
}

char	*ft_strjoin_free_first_sf(char *s1, char *s2)
{
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	dst = ft_strjoin(s1, s2);
	free(s1);
	return (dst);
}

char	*ft_strjoin_sf(char *s1, char *s2)
{
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	return (ft_strjoin(s1, s2));
}
