/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_made_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:54:31 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/22 18:15:05 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_is_made_of(char *str, char *base)
{
	while (*str)
	{
		if (!is_from(*str, base))
			return (0);
		str++;
	}
	return (1);
}
