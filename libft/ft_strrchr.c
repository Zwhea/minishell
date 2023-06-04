/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:43:17 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/15 22:52:51 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*pin;

	if ((unsigned char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	pin = NULL;
	tmp = ft_strchr(s, c);
	while (tmp != NULL)
	{
		pin = (char *)tmp;
		tmp = ft_strchr(tmp + 1, c);
	}
	return (pin);
}
