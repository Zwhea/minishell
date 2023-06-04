/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:32:37 by twang             #+#    #+#             */
/*   Updated: 2023/01/17 19:37:43 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_base(unsigned long nbr, char *base, int fd)
{
	size_t				base_size;
	size_t				size;

	base_size = ft_strlen(base);
	size = 0;
	if (nbr < base_size)
		size += ft_putchar_fd(base[nbr], fd);
	else
	{
		size += ft_putnbr_base(nbr / base_size, base, fd);
		size += ft_putchar_fd(base[nbr % base_size], fd);
	}
	return (size);
}
