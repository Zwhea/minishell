/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_constructor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:11:04 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/30 17:05:36 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_token	*_token_lst_constructor_ep(t_token *trash, t_token *ret_val);

/*----------------------------------------------------------------------------*/

t_token	*token_lst_constructor(char *str)
{
	t_token	*token;
	t_token	*pin;

	token = token_constructor(START, STRT_CHR);
	if (token == NULL)
		return (NULL);
	pin = token;
	while (*str != EOSTR)
	{
		pin->next = token_constructor(LETTER, *str);
		if (!pin->next)
			return (_token_lst_constructor_ep(token, NULL));
		pin = pin->next;
		str++;
	}
	pin->next = token_constructor(EOL, EOSTR);
	if (pin->next == NULL)
		return (_token_lst_constructor_ep(token, NULL));
	return (token);
}

static t_token	*_token_lst_constructor_ep(t_token *trash, t_token *ret_val)
{
	token_lst_clear(trash);
	return (ret_val);
}
