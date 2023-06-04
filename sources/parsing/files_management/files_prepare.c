/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_prepare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:22:53 by wangthea          #+#    #+#             */
/*   Updated: 2023/05/30 15:40:48 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_opened_infiles(t_data *data, int block_id)
{
	if (data->cmds_block[block_id].infile > 2)
		close(data->cmds_block[block_id].infile);
	if (data->cmds_block[block_id].is_heredoc == true)
	{
		free(data->cmds_block[block_id].heredoc_data);
		data->cmds_block[block_id].is_heredoc = false;
	}
}

void	check_opened_outfiles(t_data *data, int block_id)
{
	if (data->cmds_block[block_id].outfile > 2)
		close(data->cmds_block[block_id].outfile);
}

bool	file_is_empty(char *file)
{
	char	*dup;
	char	*dst;

	dup = ft_strdup(file);
	if (!dup)
	{
		perror("duplicating file");
		return (true);
	}
	dst = ft_strchr(dup, - '"');
	while (dst)
	{
		ft_memmove(dst, dst + 1, ft_strlen(dst));
		dst = ft_strchr(dup, - '"');
	}
	dst = ft_strchr(dup, - '\'');
	while (dst)
	{
		ft_memmove(dst, dst + 1, ft_strlen(dst));
		dst = ft_strchr(dup, - '\'');
	}
	if (*dup)
		return (free(dup), true);
	free(dup);
	return (false);
}

t_return_status	redirection_syntax_error(char *str)
{
	char	*tmp;

	if (str == NULL)
	{
		perror("formating");
		return (FAILURE);
	}
	tmp = ft_strjoin("syntax error near unexpected token : '", str);
	free(str);
	if (!tmp)
	{
		free(tmp);
		return (perror("syntax error warning"), FAILURE);
	}
	write(2, tmp, ft_strlen(tmp));
	free(tmp);
	g_ret_val = 2;
	return (FAILURE);
}

bool	redir_failed(t_cmd *cmd)
{
	if (cmd->infile < 0
		|| cmd->outfile < 0
		|| cmd->fd_hd[0] < 0
		|| cmd->is_ambiguous == true)
		return (true);
	return (false);
}
