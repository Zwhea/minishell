/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:15:54 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/02 18:38:25 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

bool	ft_isnbr(char *c)
{
	while (*c == ' ')
		c++;
	if (!ft_isdigit(*c) && *c != '-' && *c != '+')
		return (false);
	c++;
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (false);
		c++;
	}
	return (true);
}
