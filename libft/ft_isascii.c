/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:33:26 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/30 17:04:12 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

bool	ft_str_is_ascii(char *str)
{
	while (*str)
	{
		if (ft_isascii(*str) == false)
			return (false);
		str++;
	}
	return (true);
}
