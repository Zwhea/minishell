/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:34:32 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/27 15:34:34 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	check_arguments(char **av)
{
	if (av[1] != NULL)
	{
		ft_dprintf(2, "minishell: %s: ", av[1]);
		ft_dprintf(2, "the arguments are not processed.\n");
		ft_dprintf(2, YELLOW"usage: ");
		ft_dprintf(2, "please run the program without any arguments.\n"END);
		return (FAILURE);
	}
	else
		return (SUCCESS);
}
