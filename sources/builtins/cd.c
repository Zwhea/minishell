/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:57:56 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/29 17:52:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_update_pwd_var(char *pwd, char ***env);

/*----------------------------------------------------------------------------*/

t_return_status	cd_builtin(char **av, char ***env_pt)
{
	char	*pwd;

	pwd = NULL;
	(void)env_pt;
	if (ft_str_array_len(av) != 2)
	{
		g_ret_val = 1;
		return (dprintf(2, "cd: bad arguments number\n"), 1);
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_dprintf(2, "cd: error retrieving current directory:");
		perror("getcwd");
	}
	if (chdir(av[1]) == -1)
	{
		g_ret_val = 1;
		return (free(pwd), perror(av[1]), FAILURE);
	}
	g_ret_val = 0;
	if (_update_pwd_var(pwd, env_pt) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static t_return_status	_update_pwd_var(char *pwd, char ***env)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*tmp;

	if (pwd)
	{
		old_pwd = ft_strjoin("OLDPWD=", pwd);
		free(pwd);
		if (old_pwd == NULL)
			return (FAILED_MALLOC);
		if (is_a_key_from_env("OLDPWD", *env) != true)
			add_str_to_env(old_pwd, env);
		else
			replace_content_in_env(old_pwd, *env);
	}
	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
		return (free(old_pwd), FAILED_MALLOC);
	new_pwd = ft_strjoin("PWD=", tmp);
	free(tmp);
	if (is_a_key_from_env("PWD", *env) != true)
		return (add_str_to_env(new_pwd, env));
	replace_content_in_env(new_pwd, *env);
	return (SUCCESS);
}
