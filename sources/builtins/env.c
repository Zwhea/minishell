/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:58:14 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 16:53:02 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	env_builtin(char **av, char ***env_pt)
{
	char	**pin;

	(void)av;
	pin = *env_pt;
	while (*pin)
	{
		if (ft_strchr(*pin, '='))
			printf("%s\n", *pin);
		pin++;
	}
	g_ret_val = 0;
	return (SUCCESS);
}
