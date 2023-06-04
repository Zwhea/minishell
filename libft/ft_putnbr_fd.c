/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:32:37 by twang             #+#    #+#             */
/*   Updated: 2022/11/23 16:18:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	size;

	size = 0;
	if (n == -2147483648)
		size += ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n >= 0 && n <= 9)
			size += ft_putchar_fd((n + '0'), fd);
		if (n < 0)
		{
			size += ft_putchar_fd('-', fd);
			size += ft_putnbr_fd((n *(-1)), fd);
		}
		if (n > 9)
		{
			size += ft_putnbr_fd(n / 10, fd);
			size += ft_putnbr_fd(n % 10, fd);
		}
	}
	return (size);
}
