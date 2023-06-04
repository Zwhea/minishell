/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:57:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 19:48:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_constructor(t_emt emt, char msg)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (perror("token_constructor"), NULL);
	new->token = emt;
	new->sign_char = msg;
	new->next = NULL;
	new->esec = UNSECURED;
	new->next_word = NULL;
	return (new);
}

void	token_lst_clear(t_token *trash)
{
	t_token	*tmp;

	while (trash)
	{
		tmp = trash->next;
		del_token(trash);
		trash = tmp;
	}
}

void	del_next_token(t_token *token)
{
	t_token	*tmp;

	tmp = token->next->next;
	del_token(token->next);
	token->next = tmp;
}
