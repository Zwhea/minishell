/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:15:44 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 17:16:35 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	check_line(char *line)
{
	int	nb_of_stars;

	nb_of_stars = 0;
	while (*line)
	{
		if (*line == - '*')
			nb_of_stars++;
		if (*line == '/' && nb_of_stars > 0)
		{
			ft_dprintf(2, RED"minishell: /: wildcards can be used only");
			ft_dprintf(2, " in the current directory\n"END);
			return (SUCCESS);
		}
		line++;
	}
	return (SUCCESS);
}

void	replace_wild_card(char *line)
{
	while (*line)
	{
		if (*line == - '*')
			*line = '*';
		line++;
	}
}
