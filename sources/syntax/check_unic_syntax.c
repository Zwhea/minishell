/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unic_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:56:02 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/30 16:02:11 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	update_to_filename(t_string_token **tmp)
{
	if ((*tmp)->next->token != STRING)
	{
		(*tmp)->token = SYN_ERR;
		return (false);
	}
	(*tmp)->next->token = FILE_NAME;
	(*tmp) = (*tmp)->next;
	return (true);
}

bool	update_to_hr_data(t_string_token **tmp)
{
	if ((*tmp)->next->token != STRING)
	{
		(*tmp)->token = SYN_ERR;
		return (false);
	}
	(*tmp)->next->token = HR_DATA;
	(*tmp) = (*tmp)->next;
	return (true);
}

bool	dn_ut(t_string_token **tmp)
{
	*tmp = (*tmp)->next;
	return (true);
}

bool	update_meta(t_string_token **tmp)
{
	if ((*tmp)->next->token == EOL || (*tmp)->next->token == PIPE
		|| (*tmp)->next->token == OR || (*tmp)->next->token == AND)
	{
		(*tmp)->token = SYN_ERR;
		return (false);
	}
	(*tmp) = (*tmp)->next;
	return (true);
}

void	update_tokens(t_string_token *str_tok_lst)
{
	const t_act_update	ft_arr[] = {&dn_ut, &update_meta, &dn_ut, \
	&update_to_filename, &update_to_filename, &update_meta, \
	&update_meta, &update_to_hr_data, &update_to_filename, \
	&dn_ut, &dn_ut, dn_ut, &dn_ut, &dn_ut, &dn_ut, &dn_ut, \
	&dn_ut, &dn_ut, &dn_ut, &dn_ut, &dn_ut};
	t_string_token		*tmp;

	tmp = str_tok_lst;
	while (tmp->token != EOL)
	{
		if (!ft_arr[tmp->token](&tmp))
			return ;
	}
	return ;
}
