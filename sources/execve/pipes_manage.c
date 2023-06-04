/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:31:24 by twang             #+#    #+#             */
/*   Updated: 2023/05/19 12:40:52 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_the_pipe(t_data *data, int block_id)
{
	t_cmd	*cmd;

	cmd = &(data->cmds_block[block_id]);
	if (cmd->fd_hd[0] == 0)
		return ;
	if (cmd->outfile == STDOUT_FILENO)
		cmd->outfile = cmd->fd_hd[1];
	else
		close(cmd->fd_hd[1]);
	if ((cmd + 1)->infile == STDIN_FILENO)
		(cmd + 1)->infile = cmd->fd_hd[0];
	else
		close(data->cmds_block[block_id].fd_hd[0]);
}

t_return_status	do_the_pipe(t_cmd *cmd_block, \
						int nb_of_pipe, int block_id)
{
	if (block_id == nb_of_pipe)
		return (SUCCESS);
	if (pipe(cmd_block->fd_hd) != 0)
		return (FAILURE);
	return (SUCCESS);
}
