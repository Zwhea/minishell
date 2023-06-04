/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:41:57 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 18:55:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	get_raw_cmds(t_data *data, t_string_token *lst_of_tok, \
										char **env);
static void				set_id_cmds(t_data *data);

/*----------------------------------------------------------------------------*/

void	strings_management(t_data *data, t_string_token *lst_of_tok, char **env)
{
	get_raw_cmds(data, lst_of_tok, env);
	set_id_cmds(data);
}

static t_return_status	get_raw_cmds(t_data *data, t_string_token *lst_of_tok, \
										char **env)
{
	t_string_token	*temp;
	int				block_id;

	block_id = 0;
	temp = lst_of_tok;
	while (temp->token != EOL)
	{
		if (temp->next->token == O_PRTSS)
			data->cmds_block[block_id].commands = subshell_preparation(&temp);
		else
		{
			if (join_token_lst_on(&(data->cmds_block[block_id]), &temp, env) \
					!= SUCCESS)
				return (FAILED_MALLOC);
		}
		block_id++;
	}
	data->cmds_block[block_id].commands = NULL;
	if (!data->cmds_block[block_id].commands)
		return (FAILED_MALLOC);
	return (SUCCESS);
}

static void	set_id_cmds(t_data *data)
{
	int	block_id;

	block_id = 0;
	while (data->cmds_block[block_id].commands)
	{
		if (data->cmds_block[block_id].id_command != SUBSHELL && \
				data->cmds_block[block_id].id_command != EMPTY)
			data->cmds_block[block_id].id_command \
				= is_builtin(data->cmds_block[block_id].commands[0]);
		block_id++;
	}
}
