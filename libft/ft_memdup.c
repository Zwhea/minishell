/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:26:29 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:26:33 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *mem, size_t size)
{
	char	*str;
	char	*pin;

	str = malloc(size);
	if (!str)
		return (NULL);
	pin = str;
	while (size--)
		*(pin++) = *(char *)mem++;
	return (str);
}
