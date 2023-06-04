/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:37 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/10 19:26:47 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>

static int	ret_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*tmp;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len = ret_min(ft_strlen(s + start), len);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst || !s)
		return (NULL);
	tmp = dst;
	while (*s && start--)
		s++;
	while (*s && len--)
		*(tmp++) = *(s++);
	*tmp = 0;
	return (dst);
}

t_return_status	ft_substr_on(char const *s, unsigned int start, \
							size_t len, char **line_pt)
{
	char	*new;

	new = ft_substr(s, start, len);
	if (new == NULL)
		return (FAILED_MALLOC);
	*line_pt = new;
	return (SUCCESS);
}
