/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:58:42 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 16:59:09 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	pwd_builtin(char **args, char ***env_pt)
{
	char	*pwd;

	(void)args;
	(void)env_pt;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ft_dprintf(2, \
		"Sorry bro, you're lost bro 🤷\n"), FAILURE);
	printf("%s\n", pwd);
	free(pwd);
	g_ret_val = 0;
	return (SUCCESS);
}
