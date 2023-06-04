/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:18:10 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/09 17:31:08 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_skipspace(const char *ptr)
{
	char	*set;

	set = " \t\f\r\v\n";
	while (*set)
	{
		if (*ptr == *set)
		{
			ptr++;
			set = " \t\f\r\v\n";
		}
		else
			set++;
	}
	return (ptr);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	counter;

	sign = 1;
	nptr = ft_skipspace(nptr);
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	res = 0;
	while (*nptr)
	{
		counter = 0;
		while ("0123456789"[counter] != *nptr && counter < 10)
			counter++;
		if (counter == 10)
			return (sign * res);
		res = res * 10 + counter;
		nptr++;
	}
	return (sign * res);
}

int	ft_atoi_check_of(char *str)
{
	if (*str != '-' || *(str + 1) != '1' || *(str + 2) != 0)
		return (1);
	return (0);
}
