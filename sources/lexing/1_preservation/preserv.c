/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preserv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:57:05 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 19:38:34 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static void		wildcards_discard(t_token *token);
static size_t	_code_from(char code);
t_return_status	do_nothing(t_token *voided, \
							t_token *also_voided, t_token **this_one_too);

/*----------------------------------------------------------------------------*/

t_return_status	preserve_token_lst(t_token *token)
{
	t_token				*pin;
	const t_preserv_act	act[] = {squoting_process, \
			dquoting_process, \
			do_nothing};
	t_token				*tmp;

	tmp = token;
	pin = token->next;
	while (token->token != EOL)
	{
		if (act[_code_from(pin->sign_char)](token, pin, &token) != SUCCESS)
			return (FAILURE);
		if (token)
			pin = token->next;
	}
	wildcards_discard(tmp);
	return (SUCCESS);
}

static void	wildcards_discard(t_token *token)
{
	while (token->token != EOL)
	{
		if (token->esec != SECURED && token->sign_char == '*')
			token->sign_char = - '*';
		token = token->next;
	}
}

static size_t	_code_from(char code)
{
	const char	*charset = "\'\"";
	char		*tmp;

	tmp = ft_strchr(charset, code);
	if (tmp == NULL)
		return (DONO_INDX);
	return (tmp - charset);
}

t_return_status	do_nothing(t_token *voided, t_token *also_voided, \
							t_token **this_one_too)
{
	(void)voided;
	(void)also_voided;
	(void)this_one_too;
	*this_one_too = (*this_one_too)->next;
	return (SUCCESS);
}
