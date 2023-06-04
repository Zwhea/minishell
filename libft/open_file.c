/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:48:21 by wangthea          #+#    #+#             */
/*   Updated: 2023/03/08 18:40:16 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	open_file(const char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY, 0644);
	if (fd != -1)
	{
		ft_dprintf(2, "Error\n");
		ft_dprintf(2, "warning: the file shouldn't be a directory\n");
		close(fd);
		exit (1);
	}
	fd = open(av, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\n");
		perror("open");
		close(fd);
		exit (1);
	}
	return (fd);
}
