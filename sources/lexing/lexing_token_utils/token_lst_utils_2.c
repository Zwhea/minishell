/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:58:51 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 19:47:43 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_token(t_token *token)
{
	token_lst_clear(token->next_word);
	free(token);
}

int	len_to_next_type(t_token *pin)
{
	int	i;

	if (pin->token == LETTER)
	{
		i = 0;
		while (pin->token == LETTER)
		{
			pin = pin->next;
			i++;
		}
		return (i);
	}
	else
		return (1);
}
