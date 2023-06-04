/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_articulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:20:01 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 15:31:51 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	_meta_is_in(t_emt emt, t_string_token *token);

t_return_status	get_lexed_str_token_lst_from_line(char *line, \
		t_string_token **str_tok_pt, char **env)
{
	t_token			*simple_tok_lst;
	t_string_token	*str_token_lst;

	(void)env;
	simple_tok_lst = token_lst_constructor(line);
	free(line);
	if (simple_tok_lst == NULL)
		return (FAILED_MALLOC);
	if (preserve_token_lst(simple_tok_lst) != SUCCESS)
		return (FAILURE);
	split_toklst_on_meta(simple_tok_lst);
	regroup_meta(simple_tok_lst);
	str_token_lst = token_lst_to_str_token(simple_tok_lst);
	if (_meta_is_in(AMPERSAND, str_token_lst))
	{
		g_ret_val = 1;
		ft_dprintf(2, \
		"Error : caracter & is not managed\nTry to put it between quotes\n");
		return (string_token_destructor(str_token_lst), FAILURE);
	}
	if (str_token_lst == NULL)
		return (FAILED_MALLOC);
	del_space_token(str_token_lst);
	*str_tok_pt = str_token_lst;
	return (SUCCESS);
}

static bool	_meta_is_in(t_emt emt, t_string_token *token)
{
	while (token->token != EOL)
	{
		if (token->token == emt)
			return (true);
		token = token->next;
	}
	return (false);
}
