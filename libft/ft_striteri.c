/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:30 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/27 14:41:38 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (*s)
		(*f)(i++, s++);
}

void	ft_arriteri(void **arr, void *(*f)(char **))
{
	while (*arr)
	{
		(*f)(*arr);
		arr++;
	}
}
