/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_preparation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:50:49 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 16:36:02 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**subshell_preparation(t_string_token **start)
{
	t_string_token	*ret_val;
	t_string_token	*pin;

	ret_val = (*start)->next;
	go_to_next_(C_PRTSS, ret_val->next, &pin);
	ret_val->token = START;
	pin->token = EOL;
	(*start)->next = pin->next;
	pin->next = NULL;
	*start = (*start)->next;
	return ((char **)ret_val);
}
