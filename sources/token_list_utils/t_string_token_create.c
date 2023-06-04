/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_tokens_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:30:13 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 19:30:44 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_string_token	*string_token_creator(void)
{
	t_string_token	*new;

	new = malloc(sizeof(t_string_token));
	if (new == NULL)
		return (perror("string token creator"), NULL);
	new->next = NULL;
	new->content = NULL;
	new->token = NONE;
	return (new);
}

t_return_status	string_token_creator_on(t_string_token **tok_pt)
{
	t_string_token	*new;

	new = string_token_creator();
	if (new == NULL)
		return (FAILED_MALLOC);
	*tok_pt = new;
	return (SUCCESS);
}
