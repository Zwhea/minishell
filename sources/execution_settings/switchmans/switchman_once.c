/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchman_once.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:58:48 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 17:06:46 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_execute_son(t_data *data, t_cmd cmd, char ***env_pt);
static void				_close_switchman_once(t_cmd cmd);
static t_return_status	_switchman_once_ep(t_data *data);
static void				_waiting(int pid);

/*----------------------------------------------------------------------------*/

t_return_status	switchman_once(t_data *data, char ***env_pt)
{
	int		pid;
	t_cmd	cmd;

	cmd = *(data->cmds_block);
	if (cmd.id_command == EXIT)
		return (exit_the_program(data, env_pt, cmd));
	if (cmd.id_command > PWD
		|| (cmd.id_command == EXPORT && cmd.commands[1] != NULL))
		return (builtin_switch_free(cmd, cmd.commands, env_pt));
	pid = fork();
	if (pid == -1)
		return (_switchman_once_ep(data));
	if (pid == 0)
		_execute_son(data, cmd, env_pt);
	_waiting(pid);
	ft_free_split(cmd.commands);
	_close_switchman_once(cmd);
	return (SUCCESS);
}

static void	_waiting(int pid)
{
	int	status;

	status = 0;
	if (waitpid(pid, &status, WUNTRACED) == -1)
		g_ret_val = 1;
	else if (WIFEXITED(status))
		g_ret_val = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_ret_val = WTERMSIG(status);
		if (g_ret_val != 131)
			g_ret_val += 128;
	}
}

static t_return_status	_execute_son(t_data *data, t_cmd cmd, char ***env_pt)
{
	free(data->cmds_block);
	get_prompt(NULL, 2);
	ft_free_all_str_lst(data, data->index);
	if (duplicate_fds(cmd, data, env_pt) != SUCCESS)
	{
		ft_free_split(cmd.commands);
		ft_free_split(*env_pt);
		g_ret_val = 1;
		exit(1);
	}
	builtin_switch(cmd, cmd.commands, env_pt);
	ft_free_split(*env_pt);
	if (cmd.id_command != EXPORT)
		ft_free_split(cmd.commands);
	else
	{
		free(*(cmd.commands));
		free(cmd.commands);
	}
	exit(SUCCESS);
}

static void	_close_switchman_once(t_cmd cmd)
{
	if (cmd.infile > 2)
		close(cmd.infile);
	if (cmd.outfile > 2)
		close(cmd.outfile);
}

static t_return_status	_switchman_once_ep(t_data *data)
{
	ft_free_split(data->cmds_block->commands);
	perror("fork switchman once");
	return (FAILURE);
}
