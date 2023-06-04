/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:46:01 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 22:30:03 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	close_pipe_arr(int **pipe_arr)
{
	while (*pipe_arr)
	{
		close((*pipe_arr)[0]);
		close((*pipe_arr)[1]);
		pipe_arr++;
	}
}

void	ft_print_pipe_arr(int **pipe_arr)
{
	write(1, "pipe arr\n", 9);
	while (*pipe_arr)
	{
		ft_putnbr_fd((*pipe_arr)[0], 1);
		write(1, "  ", 2);
		ft_putnbr_fd((*pipe_arr)[1], 1);
		write(1, "\n", 1);
		pipe_arr++;
	}
}
