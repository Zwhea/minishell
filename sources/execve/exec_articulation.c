/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_articulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:54:36 by wangthea          #+#    #+#             */
/*   Updated: 2023/06/02 18:24:57 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_alloc_cmd_block(t_data *data, \
													t_string_token *lst_of_tok);
static t_return_status	_check_if_token_lst_is_empty(t_string_token \
													*lst_of_tok);
static void				_wait_for_process_ids(t_data *data);
static t_return_status	_wait_for_command(int pid, int *status, bool *signals);

/*----------------------------------------------------------------------------*/

t_return_status	execution(t_data *data, t_string_token *lst_of_tok, \
				char ***env_pt)
{
	init_data(data);
	if (_alloc_cmd_block(data, lst_of_tok) != SUCCESS
		|| files_management(data, lst_of_tok, *env_pt) != SUCCESS)
		return (string_token_destructor(lst_of_tok), FAILED_MALLOC);
	clean_files_token(lst_of_tok);
	clean_token(lst_of_tok);
	if (_check_if_token_lst_is_empty(lst_of_tok) != SUCCESS)
		return (free(data->cmds_block->heredoc_data), free(data->cmds_block), \
			string_token_destructor(lst_of_tok), SUCCESS);
	strings_management(data, lst_of_tok, *env_pt);
	string_token_destructor(lst_of_tok);
	if (g_ret_val == 130 && check_cmd(data->cmds_block))
		return (SUCCESS);
	if (data->nb_of_pipe == 0 && data->cmds_block->id_command != CMD && \
		data->cmds_block->id_command != SUBSHELL && \
		data->cmds_block->id_command != EMPTY)
		switchman_once(data, env_pt);
	else
	{
		if (childs_execve(data, env_pt) != SUCCESS)
			return (FAILURE);
		_wait_for_process_ids(data);
	}
	free(data->cmds_block);
	return (SUCCESS);
}

static t_return_status	_alloc_cmd_block(t_data *data, \
									t_string_token *lst_of_tok)
{
	t_string_token	*temp;
	int				i;

	temp = lst_of_tok;
	while (temp != NULL)
	{
		if (temp->token == O_PRTSS)
			go_to_next_(C_PRTSS, temp->next, &temp);
		if (temp->token == PIPE)
			data->nb_of_pipe++;
		temp = temp->next;
	}
	if (data->nb_of_pipe > 3332)
	{
		ft_dprintf(2, "minishell: syntax error near unexpected token `|'\n");
		g_ret_val = 2;
		return (FAILURE);
	}
	data->cmds_block = ft_calloc((data->nb_of_pipe + 2), sizeof(t_cmd));
	if (!data->cmds_block)
		return (perror("alloc_cmd_block"), FAILED_MALLOC);
	i = 0;
	while (i < data->nb_of_pipe + 1)
		data->cmds_block[i++].outfile = 1;
	return (SUCCESS);
}

static t_return_status	_check_if_token_lst_is_empty(t_string_token *lst_of_tok)
{
	t_string_token	*temp;

	temp = lst_of_tok;
	while (temp != NULL)
	{
		if (temp->token != START && temp->token != EOL)
			return (SUCCESS);
		temp = temp->next;
	}
	return (FAILURE);
}

static void	_wait_for_process_ids(t_data *data)
{
	int		block_id;
	int		status;
	bool	signals;

	block_id = 0;
	status = 0;
	signals = false;
	while (block_id < data->nb_of_pipe + 1)
	{
		if (_wait_for_command(data->cmds_block[block_id].process_id, \
								&status, &signals) == false)
			break ;
		block_id++;
	}
}

static t_return_status	_wait_for_command(int pid, int *status, bool *signals)
{
	if (waitpid(pid, status, WUNTRACED) == -1)
	{
		g_ret_val = 1;
		return (false);
	}
	else if (WIFEXITED(*status))
		g_ret_val = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status) && *signals == false)
	{
		handle_signal_child(WTERMSIG(*status));
		*signals = true;
	}
	return (true);
}
