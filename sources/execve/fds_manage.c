/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:26:01 by twang             #+#    #+#             */
/*   Updated: 2023/06/02 18:22:34 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_dup_n_close(int to_dup, int to_replace);
static t_return_status	_write_all(char *str, int fd);
static void				_heredoc_forking(int *fd, t_cmd *cmd, t_data *data, \
											char **env_pt);

/*----------------------------------------------------------------------------*/

t_return_status	duplicate_fds(t_cmd block, t_data *data, char ***env_pt)
{
	if (block.is_heredoc == true
		&& heredoc_child_management(&block, data, *env_pt) != SUCCESS)
		return (FAILURE);
	if (block.infile == -1 || block.outfile == -1)
		return (FAILURE);
	if (block.is_ambiguous)
		return (FAILURE);
	if (_dup_n_close(block.infile, STDIN_FILENO) != SUCCESS
		|| _dup_n_close(block.outfile, STDOUT_FILENO) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static t_return_status	_dup_n_close(int to_dup, int to_replace)
{
	if (to_dup == to_replace)
		return (SUCCESS);
	if (dup2(to_dup, to_replace) == -1)
	{
		close(to_dup);
		return (FAILURE);
	}
	close(to_dup);
	return (SUCCESS);
}

t_return_status	heredoc_child_management(t_cmd *cmd, t_data *data, \
										char **env_pt)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (free(cmd->heredoc_data), perror("pipe"), FAILURE);
	pid = fork();
	if (pid == -1)
		return (free(cmd->heredoc_data), perror("heredoc"), FAILURE);
	if (pid == 0)
		_heredoc_forking(fd, cmd, data, env_pt);
	free(cmd->heredoc_data);
	close(fd[1]);
	cmd->infile = fd[0];
	return (SUCCESS);
}

static void	_heredoc_forking(int *fd, t_cmd *cmd, t_data *data, char **env_pt)
{
	(void)data;
	ft_free_split(env_pt);
	ft_free_split(cmd->commands);
	close(cmd->infile);
	close(cmd->outfile);
	close(fd[0]);
	if (_write_all(cmd->heredoc_data, fd[1]) != SUCCESS)
	{
		free(cmd->heredoc_data);
		exit(FAILURE);
	}
	close(fd[1]);
	free(cmd->heredoc_data);
	exit(SUCCESS);
}

static t_return_status	_write_all(char *str, int fd)
{
	int	flag;

	flag = 1;
	if (!str)
		return (close(fd), FAILURE);
	while (flag == 1 && *str)
	{
		flag = write(fd, str, 1);
		str++;
	}
	close(fd);
	if (flag == -1)
		return (FAILURE);
	return (SUCCESS);
}
