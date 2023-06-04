/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:41:33 by wangthea          #+#    #+#             */
/*   Updated: 2023/06/02 12:11:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	is_builtin(char *string)
{
	t_builtin	ret_val;
	const char	*name_arr[] = {NULL, "env", "echo", "export", \
							"pwd", "exit", "unset", "cd", ""};

	ret_val = ENV;
	if (!string)
		return (CMD);
	while (ret_val < 8)
	{
		if (ft_strcmp(string, (char *)name_arr[ret_val]) == 0)
			return (ret_val);
		ret_val++;
	}
	return (CMD);
}

t_return_status	builtin_switch(t_cmd command, char **av, char ***env_pt)
{
	const t_builtin_ft	ft_arr[] = {NULL, &env_builtin, &echo_builtin, \
									&export_builtin, &pwd_builtin, \
									&exit_builtin, &unset_builtin, \
									&cd_builtin};
	t_return_status		ret_val;

	ret_val = (*ft_arr[command.id_command])(av, env_pt);
	if (command.infile > 2)
		close(command.infile);
	if (command.outfile > 2)
		close(command.outfile);
	return (ret_val);
}

t_return_status	builtin_switch_free(t_cmd command, char **av, char ***env_pt)
{
	const t_builtin_ft	ft_arr[] = {NULL, &env_builtin, &echo_builtin, \
									&export_builtin, &pwd_builtin, \
									&exit_builtin, &unset_builtin, \
									&cd_builtin};
	t_return_status		ret_val;

	ret_val = (*ft_arr[command.id_command])(av, env_pt);
	if (command.infile > 2)
		close(command.infile);
	if (command.outfile > 2)
		close(command.outfile);
	if (command.id_command != EXPORT)
		ft_free_split(av);
	else
	{
		free(*av);
		free(av);
	}
	return (ret_val);
}

bool	is_path(char *line)
{
	return (ft_strchr(line, '/') != NULL);
}
