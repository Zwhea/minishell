/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:25 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/04/18 16:07:08 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *src)
{
	char	*dst;
	char	*tmp;

	tmp = (char *)src;
	while (*tmp)
		tmp++;
	dst = malloc(tmp - src + 1);
	if (!dst)
		return (NULL);
	tmp = dst;
	while (*src)
		*(tmp++) = *(src++);
	*tmp = 0;
	return (dst);
}

t_return_status	ft_strdup_on(const char *src, char **str_pt)
{
	char	*new;

	new = ft_strdup(src);
	if (new == NULL)
		return (FAILED_MALLOC);
	*str_pt = new;
	return (SUCCESS);
}

char	*ft_strndup(char *s1, int size)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup)
	{
		while (i < size && s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}
