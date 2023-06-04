/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:07 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/01/05 17:43:51 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_wc(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	ft_allocate(char **dst, const char *s, char c)
{
	unsigned int	idx;
	unsigned int	ln;

	idx = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		ln = 0;
		while (*s != c && *s)
		{
			s++;
			ln++;
		}
		if (ln != 0)
		{
			dst[idx] = malloc(ln + 1);
			if (!dst[idx])
				return (idx);
			idx++;
		}
	}
	dst[idx] = NULL;
	return (-1);
}

static void	ft_fill(char **dst, const char *s, char c)
{
	unsigned int	idx;
	unsigned int	ln;

	idx = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		ln = 0;
		while (*s != c && *s)
		{
			dst[idx][ln++] = *s;
			s++;
		}
		if (ln != 0)
			dst[idx][ln] = 0;
		idx++;
	}
}

void	*ft_free_split(char **dst)
{
	int	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		ernum;

	dst = malloc(sizeof(char *) * (ft_wc(s, c) + 1));
	if (!dst)
		return (NULL);
	ernum = ft_allocate(dst, s, c);
	if (ernum != -1)
		return (ft_free_split(dst));
	ft_fill(dst, s, c);
	return (dst);
}
