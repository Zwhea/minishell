/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:53:13 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/18 19:26:04 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_get_str_token_on_and_reset_pin( \
								t_string_token **str_tok_pt, t_token **pin_pt);
static void				*_token_lst_to_str_token_ep( \
								t_token *trash, t_string_token *mem);
static char				*_reset_pin_ret_string(t_token **pin_pt);

/*----------------------------------------------------------------------------*/

t_string_token	*token_lst_to_str_token(t_token *tok)
{
	t_string_token	*str_token_list;
	t_string_token	*mem;
	t_token			*pin;

	mem = NULL;
	if (string_token_creator_on(&str_token_list) != SUCCESS)
		return (_token_lst_to_str_token_ep(tok, mem));
	str_token_list->token = START;
	mem = str_token_list;
	pin = tok->next;
	while (pin->token != EOL)
	{
		if (_get_str_token_on_and_reset_pin(&str_token_list->next, \
		&pin) != SUCCESS)
			return (_token_lst_to_str_token_ep(tok, mem));
		str_token_list = str_token_list->next;
	}
	if (string_token_creator_on(&str_token_list->next) != SUCCESS)
		return (_token_lst_to_str_token_ep(tok, mem));
	str_token_list->next->token = EOL;
	token_lst_clear(tok);
	return (mem);
}

static t_return_status	_get_str_token_on_and_reset_pin( \
					t_string_token **str_tok_pt, t_token **pin_pt)
{
	t_emt	tmp;

	if (string_token_creator_on(str_tok_pt) != SUCCESS)
		return (FAILURE);
	tmp = (*pin_pt)->token;
	(*str_tok_pt)->content = _reset_pin_ret_string(pin_pt);
	if ((*str_tok_pt)->content == NULL)
		return (FAILURE);
	if (tmp == LETTER)
		(*str_tok_pt)->token = STRING;
	else
		(*str_tok_pt)->token = tmp;
	if (errno)
	{
		errno = SUCCESS;
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	*_token_lst_to_str_token_ep( \
					t_token *trash, t_string_token *trashy_string_token)
{
	token_lst_clear(trash);
	string_token_destructor(trashy_string_token);
	return (NULL);
}

static char	*_reset_pin_ret_string(t_token **pin_pt)
{
	char	*new;
	int		len;

	len = len_to_next_type(*pin_pt);
	new = malloc(len + 1);
	if (new == NULL)
		return (perror("reset_pin_ret_string"), NULL);
	cpy_token_lst_to_str(*pin_pt, new);
	while (len--)
		*pin_pt = (*pin_pt)->next;
	return (new);
}
