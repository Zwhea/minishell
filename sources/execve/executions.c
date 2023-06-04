/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:41:45 by twang             #+#    #+#             */
/*   Updated: 2023/06/02 18:18:48 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	subshell_then_exit(t_cmd command, char ***env)
{
	t_data	new_data;

	ft_bzero(&new_data, sizeof(t_data));
	switchman(&new_data, (t_string_token *)command.commands, env);
	ft_free_split(*env);
	exit(g_ret_val);
}

void	builtin_then_exit(t_cmd command, char ***env)
{
	builtin_switch(command, command.commands, \
						env);
	if (command.id_command == EXPORT)
	{
		free(command.commands[0]);
		free(command.commands);
	}
	else
		ft_free_split(command.commands);
	ft_free_split(*env);
	exit(0);
}

void	execve_then_exit(t_cmd command, char ***env)
{
	char			*command_str;

	command_str = NULL;
	if (command.commands != NULL)
		command_str = add_path_cmd(&command, *env);
	else
		write(2, "'' : command not found\n", 23);
	if (command_str != NULL && is_executable(command_str) == SUCCESS)
	{
		execve(command_str, command.commands, *env);
		perror(command.commands[0]);
		g_ret_val = 127;
	}
	ft_free_split(*env);
	ft_free_split(command.commands);
	exit(g_ret_val);
}
