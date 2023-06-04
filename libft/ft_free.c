/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:56:18 by twang             #+#    #+#             */
/*   Updated: 2023/05/29 15:00:12 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void **s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

void	ft_free_split_content(char **str_arr)
{
	while (*str_arr)
	{
		free(*str_arr);
		++str_arr;
	}
}
