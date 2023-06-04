/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:08:04 by twang             #+#    #+#             */
/*   Updated: 2023/05/29 19:12:54 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	false_space_to_space(char *str)
{
	while (*str)
	{
		if (*str == -32)
			*str = 32;
		str++;
	}
}

void	manage_ambiguous(t_cmd *cmd, char *file)
{
	cmd->is_ambiguous = true;
	false_space_to_space(file);
	ft_dprintf(2, "minishell: %s: ambiguous redirect\n", file);
}

t_return_status	expand_hd(char **here_doc, char **env)
{
	char	**arr;
	char	*tmp;

	if (cut_line_on(*here_doc, &arr) != SUCCESS
		|| join_arr_on(arr, here_doc, env) != SUCCESS)
		return (FAILURE);
	tmp = *here_doc;
	while (*tmp)
	{
		if (*tmp == - ' ')
			*tmp = ' ';
		tmp++;
	}
	return (SUCCESS);
}

bool	read_hd_ep(char *line, int nb_of_line, char *limiter)
{
	if (g_ret_val == 130)
		return (true);
	if (!line)
	{
		ft_dprintf(2, RED"minishell: warning: ");
		ft_dprintf(2, "here-document at line %d", nb_of_line);
		ft_dprintf(2, " delimited by end-of-file (wanted `%s')\n"END, limiter);
		return (true);
	}
	return (false);
}

t_return_status	set_files_expand(char **file, char **env, \
									t_data *data, int block_id)
{
	char	**arr;

	if (cut_line_on(*file, &arr) != SUCCESS
		|| join_arr_on(arr, file, env) != SUCCESS)
		return (FAILED_MALLOC);
	if (wildcard_files(data, file, block_id) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
