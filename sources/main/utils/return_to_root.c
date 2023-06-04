/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:27:35 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/30 17:27:37 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	return_to_root(char *line, char **env)
{
	if (chdir("/") == -1)
	{
		perror("chdir");
		clean_the_prompt(line, env);
	}
	ft_dprintf(2, "You were lost\nPitit shell bring you back to root.\n");
	ft_dprintf(2, "Stop doing shit with directories pls.\n");
	ft_dprintf(2, "PWD won't be updated until you cd again.\n");
}
