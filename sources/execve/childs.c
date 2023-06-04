/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:17:52 by twang             #+#    #+#             */
/*   Updated: 2023/06/02 18:24:07 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_fork_process(t_data *data, int pid, \
									int block_id, char ***env);
static void				_child_launch_act(t_data *data, int nb_of_pipe, \
									char ***env, int block_id);
static void				_vd_string_token_destructor(char **str_arr);

/*----------------------------------------------------------------------------*/

t_return_status	childs_execve(t_data *data, char ***env)
{
	int		block_id;

	block_id = 0;
	while (block_id < data->nb_of_pipe + 1)
	{
		if (do_the_pipe(&(data->cmds_block[block_id]), \
						data->nb_of_pipe, block_id) != SUCCESS)
			return (FAILURE);
		manage_the_pipe(data, block_id);
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		data->cmds_block[block_id].process_id = fork();
		if (_fork_process(data, data->cmds_block[block_id].process_id, \
						block_id, env) != SUCCESS)
			return (FAILURE);
		if (data->cmds_block[block_id].id_command == SUBSHELL)
			_vd_string_token_destructor(data->cmds_block[block_id].commands);
		else
			ft_free_split(data->cmds_block[block_id].commands);
		free(data->cmds_block[block_id].heredoc_data);
		close_this(data->cmds_block[block_id].infile);
		close_this(data->cmds_block[block_id].outfile);
		block_id++;
	}
	return (SUCCESS);
}

static void	_vd_string_token_destructor(char **str_arr)
{
	string_token_destructor((t_string_token *)str_arr);
}

static t_return_status	_fork_process(t_data *data, int pid, \
									int block_id, char ***env)
{
	if (pid == 0)
	{
		signal(SIGINT, &handle_signal_child);
		signal(SIGQUIT, &handle_signal_child);
		ft_free_all_str_lst(data, data->index);
		get_prompt(NULL, 2);
		free_all_others(data->cmds_block, block_id, data->nb_of_pipe);
		_child_launch_act(data, data->nb_of_pipe, env, block_id);
	}
	else if (pid < 0)
	{
		perror("fork");
		ft_free_split(data->cmds_block[block_id].commands);
		free(data->cmds_block[block_id].heredoc_data);
		ft_dprintf(2, \
			RED"minishell: fork: ressource temporarily unavailable\n"END);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	_child_launch_act(t_data *data, int nb_of_pipe, \
								char ***env, int block_id)
{
	t_cmd			command_block;

	command_block = data->cmds_block[block_id];
	free(data->cmds_block);
	if (block_id <= nb_of_pipe)
		close_this(command_block.fd_hd[0]);
	if (duplicate_fds(command_block, data, env) != SUCCESS)
	{
		close_this(command_block.infile);
		close_this(command_block.outfile);
		ft_free_split(command_block.commands);
		ft_free_split(*env);
		exit(1);
	}
	if (command_block.id_command == SUBSHELL)
		subshell_then_exit(command_block, env);
	if (command_block.id_command != CMD && command_block.id_command != EMPTY)
		builtin_then_exit(command_block, env);
	execve_then_exit(command_block, env);
}
