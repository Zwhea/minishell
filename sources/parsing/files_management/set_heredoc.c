/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:35:20 by twang             #+#    #+#             */
/*   Updated: 2023/05/30 15:30:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_get_here_doc_in_hr_data(t_data *data, \
											t_string_token *token, char **env);
static t_return_status	_father_process_here_doc_reading(char *limiter, \
											int *fd_hd, char **dst, int pid);
static void				_get_heredoc(char *limiter, int do_expand, int *fd_hd, \
											char **env);
static t_return_status	_read_here_doc_in_str(char *limiter, \
											char **documentation);

/*----------------------------------------------------------------------------*/

t_return_status	heredoc_management(t_data *data, \
								t_string_token *string_token_lst, char **env)
{
	t_string_token	*tmp;

	tmp = string_token_lst;
	update_tokens(string_token_lst);
	if (check_closing_par(string_token_lst) == SUCCESS)
		check_par_err(string_token_lst);
	while (tmp != NULL)
	{
		if (tmp->token == HR_DATA)
		{
			if (_get_here_doc_in_hr_data(data, tmp, env) != SUCCESS)
				return (FAILED_MALLOC);
		}
		if (tmp->token == SYN_ERR)
		{
			redirection_syntax_error(format_string_token(tmp->next));
			return (FAILURE);
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static t_return_status	_get_here_doc_in_hr_data(t_data *data, \
											t_string_token *token, char **env)
{
	char	*limiter;
	int		fd_hd[2];
	bool	do_expand;
	int		pid;

	if (set_up_get_here_doc(token, &limiter, &do_expand, fd_hd))
		return (FAILED_PIPE);
	pid = fork();
	if (pid == -1)
		return (fork_heredoc_error_process(fd_hd, limiter));
	if (pid == 0)
	{
		get_heredoc_setup(data);
		_get_heredoc(limiter, do_expand, fd_hd, env);
	}
	else
	{
		if (_father_process_here_doc_reading(limiter, fd_hd, \
			&(token->content), pid) != SUCCESS)
			return (FAILURE);
	}
	if (g_ret_val == 130)
		return (FAILURE);
	return (SUCCESS);
}

static t_return_status	_father_process_here_doc_reading(char *limiter, \
				int *fd_hd, char **dst, int pid)
{
	int	status;

	free(limiter);
	close(fd_hd[1]);
	if (read_fd_in_str(fd_hd[0], dst) != SUCCESS)
		return (FAILED_MALLOC);
	close(fd_hd[0]);
	if (waitpid(pid, &status, WUNTRACED) == -1)
		g_ret_val = WEXITSTATUS(status);
	else if (WIFEXITED(status))
		g_ret_val = WEXITSTATUS(status);
	return (SUCCESS);
}

static void	_get_heredoc(char *limiter, int do_expand, int *fd_hd, char **env)
{
	char	*line;
	char	*here_doc;

	g_ret_val = 0;
	line = NULL;
	here_doc = NULL;
	here_doc = ft_strdup("n");
	if (do_expand)
		here_doc[0] = -1;
	else
		here_doc[0] = -2;
	if (!here_doc)
		perror("here doc _get_heredoc");
	_read_here_doc_in_str(limiter, &here_doc);
	free(line);
	free(limiter);
	ft_free_split(env);
	if (here_doc)
		write(fd_hd[1], here_doc, ft_strlen(here_doc));
	close(fd_hd[0]);
	close(fd_hd[1]);
	free(here_doc);
	exit(g_ret_val);
}

static t_return_status	_read_here_doc_in_str(char *limiter, \
												char **documentation)
{
	int		nb_of_line;
	char	*line;

	nb_of_line = 0;
	line = NULL;
	errno = 0;
	g_ret_val = 0;
	while (HEREDOC_MUST_GO_ON)
	{
		nb_of_line++;
		line = readline(GREEN"> "END);
		if (read_hd_ep(line, nb_of_line, limiter)
			|| !ft_strncmp(limiter, line, ft_strlen(limiter) + 1)
			|| documentation == NULL)
			break ;
		*documentation = strjoin_path_cmd(*documentation, line);
		*documentation = ft_strjoin_free_first_sf(*documentation, "\n");
		free(line);
	}
	free(line);
	if (errno)
		return (FAILURE);
	return (SUCCESS);
}
