/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:35:35 by twang             #+#    #+#             */
/*   Updated: 2023/05/30 15:44:34 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	check_closing_par(t_string_token *string_token_lst)
{
	int				open_par;
	t_string_token	*tmp;

	tmp = string_token_lst;
	open_par = 0;
	while (string_token_lst->next != NULL)
	{
		if (string_token_lst->token == O_PRTSS)
			open_par++;
		else if (string_token_lst->token == C_PRTSS)
		{
			if (--open_par < 0)
			{
				string_token_lst->token = SYN_ERR;
				return (FAILURE);
			}
		}
		string_token_lst = string_token_lst->next;
	}
	go_to_next_(O_PRTSS, tmp, &tmp);
	if (open_par > 0)
		return (tmp->token = SYN_ERR, FAILURE);
	return (SUCCESS);
}

void	get_heredoc_setup(t_data *data)
{
	struct termios	copy;

	copy = data->term;
	copy.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(1, TCSANOW, &copy) == -1)
	{
		perror("tcsetattr");
		errno = SUCCESS;
	}
	string_token_destructor(data->instructions_arr[0]);
	free(data->instructions_arr);
	get_prompt(NULL, 2);
	signal(SIGINT, &handle_signal_heredoc);
	signal(SIGQUIT, &handle_signal_heredoc);
}

t_return_status	set_up_get_here_doc(t_string_token *token, char **limiter, \
										bool *do_expand, int *fd_hd)
{
	*do_expand = false;
	*limiter = token->content;
	token->content = NULL;
	if (ft_strchr(*limiter, - '\'') || ft_strchr(*limiter, - '\"'))
	{
		*do_expand = true;
		trim_limiter(*limiter);
	}
	if (pipe(fd_hd) == -1)
		return (FAILED_PIPE);
	signal(SIGINT, SIG_IGN);
	return (SUCCESS);
}

void	trim_limiter(char *s)
{
	while (*s)
	{
		while (*s && (*s != - '\'' && *s != - '\"'))
			s++;
		if (*s == '\0')
			break ;
		ft_memmove(s, s + 1, ft_strlen(s));
	}
}

void	keep_going(int *i, t_string_token **temp, t_data *data)
{
	if ((*temp)->token == PIPE)
		(*i)++;
	if ((*temp)->token == O_PRTSS)
	{
		data->cmds_block[*i].id_command = SUBSHELL;
		go_to_next_(C_PRTSS, (*temp)->next, temp);
	}
	else
		*temp = (*temp)->next;
}
