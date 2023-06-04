/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:32:37 by twang             #+#    #+#             */
/*   Updated: 2022/11/23 18:04:19 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	size_t	size;

	size = 0;
	if (n <= 9)
	{
		size += ft_putchar_fd((n + '0'), fd);
	}
	if (n > 9)
	{
		size += ft_putnbr_unsigned_fd(n / 10, fd);
		size += ft_putnbr_unsigned_fd(n % 10, fd);
	}
	return (size);
}
