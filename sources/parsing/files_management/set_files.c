/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:08:37 by twang             #+#    #+#             */
/*   Updated: 2023/06/02 18:25:32 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	set_files_expand(char **file, char **env, \
									t_data *data, int block_id);

t_return_status	files_management(t_data *data, t_string_token *lst_of_tok, \
									char **env)
{
	int								i;
	size_t							index_ft;
	t_string_token					*temp;
	const t_files_manage_ft			arr_ft[] = {&set_infile, \
					&set_heredoc, &set_appends, &set_outfile};
	const enum e_token_minishell	arr_en[] = {CHEVRON_IN, \
					HERE_DOC, APPENDS, CHEVRON_OT};

	i = 0;
	temp = lst_of_tok;
	while (temp != NULL)
	{
		index_ft = 0;
		while (index_ft < 4 && arr_en[index_ft] != temp->token)
			index_ft++;
		if (index_ft < 4)
		{
			temp = temp->next;
			if (arr_ft[index_ft](data, &(temp->content), i, env) != SUCCESS)
				return (FAILED_MALLOC);
		}
		keep_going(&i, &temp, data);
	}
	return (SUCCESS);
}

t_return_status	set_infile(t_data *data, char **file, int block_id, \
										char **env)
{
	bool	signal;

	check_opened_infiles(data, block_id);
	signal = file_is_empty(*file);
	if (redir_failed(&(data->cmds_block[block_id])))
		return (SUCCESS);
	if (set_files_expand(file, env, data, block_id) != SUCCESS)
		return (FAILURE);
	if (ft_strchr(*file, -32) != NULL || (**file == 0 && signal))
	{
		manage_ambiguous(&(data->cmds_block[block_id]), *file);
		return (SUCCESS);
	}
	data->cmds_block[block_id].infile = open(*file, O_RDONLY, 0644);
	if (data->cmds_block[block_id].infile == -1)
	{
		g_ret_val = 1;
		perror(*file);
	}
	return (SUCCESS);
}

t_return_status	set_heredoc(t_data *data, char **hr_data, int block_id, \
										char **env)
{
	check_opened_infiles(data, block_id);
	if (redir_failed(&(data->cmds_block[block_id])) == true)
		return (SUCCESS);
	if (data->cmds_block[block_id].is_heredoc)
		free(data->cmds_block[block_id].heredoc_data);
	data->cmds_block[block_id].is_heredoc = true;
	if (*hr_data[0] == -2)
	{
		ft_memmove(*hr_data, *hr_data + 1, ft_strlen(*hr_data));
		expand_hd(hr_data, env);
	}
	else
		ft_memmove(*hr_data, *hr_data + 1, ft_strlen(*hr_data));
	data->cmds_block[block_id].heredoc_data = *hr_data;
	*hr_data = NULL;
	return (SUCCESS);
}

t_return_status	set_outfile(t_data *data, char **file, int block_id, \
										char **env)
{
	bool	signal;

	signal = file_is_empty(*file);
	check_opened_outfiles(data, block_id);
	if (redir_failed(&(data->cmds_block[block_id])))
		return (SUCCESS);
	if (set_files_expand(file, env, data, block_id) != SUCCESS)
		return (FAILURE);
	if (ft_strchr(*file, -32) != NULL || (**file == 0 && signal))
	{
		manage_ambiguous(&(data->cmds_block[block_id]), *file);
		return (SUCCESS);
	}
	data->cmds_block[block_id].outfile = open(*file, O_WRONLY | O_CREAT | \
	O_TRUNC, 0644);
	if (data->cmds_block[block_id].outfile == -1)
	{
		g_ret_val = 1;
		perror(*file);
	}
	return (SUCCESS);
}

t_return_status	set_appends(t_data *data, char **file, int block_id, \
										char **env)
{
	bool	signal;

	signal = file_is_empty(*file);
	check_opened_outfiles(data, block_id);
	if (redir_failed(&(data->cmds_block[block_id])))
		return (SUCCESS);
	if (set_files_expand(file, env, data, block_id) != SUCCESS)
		return (FAILURE);
	if (ft_strchr(*file, -32) != NULL || (**file == 0 && signal))
	{
		manage_ambiguous(&(data->cmds_block[block_id]), *file);
		return (SUCCESS);
	}
	data->cmds_block[block_id].outfile = open(*file, O_WRONLY | O_CREAT | \
	O_APPEND, 0644);
	if (data->cmds_block[block_id].outfile == -1)
	{
		g_ret_val = 1;
		perror(*file);
	}
	return (SUCCESS);
}
