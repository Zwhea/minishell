/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:49:35 by wangthea          #+#    #+#             */
/*   Updated: 2023/02/21 16:39:03 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	length_comp(char *file, char *extension)
{
	int	file_length;
	int	ext_length;

	file_length = ft_strlen(file);
	ext_length = ft_strlen(extension);
	if (file_length <= ext_length)
	{
		ft_dprintf(2, RED"Error\n"END);
		ft_dprintf(2, YELLOW"warning:"END" there is no file name\n");
		return (false);
	}
	return (true);
}

bool	check_extension(char *file, char *extension)
{
	int	i;
	int	j;

	if (!length_comp(file, extension))
		return (false);
	i = ft_strlen(file) - ft_strlen(extension) - 1;
	if (file[i] == '/')
	{
		ft_dprintf(2, RED"Error\n"END);
		ft_dprintf(2, YELLOW"warning:"END" the file name is invalid\n");
		return (false);
	}
	i++;
	j = 0;
	while (file[i])
	{
		if (file[i] != extension[j])
		{
			ft_dprintf(2, RED"Error\n"END);
			return (false);
		}
		i++;
		j++;
	}
	return (true);
}
