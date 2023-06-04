/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_token_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:25:09 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 19:31:16 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cpy_token_lst_to_str(t_token *tok, char *str)
{
	int	i;

	i = 0;
	str[0] = tok->sign_char;
	while (tok->token == LETTER)
	{
		if (!is_from(tok->sign_char, "\'\"") || tok->esec == SECURED)
		{
			str[i] = tok->sign_char;
			i++;
		}
		tok = tok->next;
	}
	str[i] = 0;
}
