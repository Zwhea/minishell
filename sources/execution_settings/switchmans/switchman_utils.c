/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchman_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:08:12 by twang             #+#    #+#             */
/*   Updated: 2023/05/30 16:19:36 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	go_to_next_(t_emt token, t_string_token *tmp, t_string_token **str_tok)
{
	size_t	l;

	l = 0;
	if (tmp == NULL)
		return (INT_MAX);
	while (tmp->token != token && tmp->token != EOL)
	{
		if (tmp->token == O_PRTSS)
		{
			l += go_to_next_(C_PRTSS, tmp->next, &tmp) + 1;
			tmp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			l++;
		}
	}
	*str_tok = tmp;
	return (l);
}

void	go_to_next_logical_door(t_string_token *src, t_string_token **dst)
{
	t_string_token	*and_pt;
	t_string_token	*or_pt;
	size_t			and_l;
	size_t			or_l;

	and_l = go_to_next_(AND, src, &and_pt);
	or_l = go_to_next_(OR, src, &or_pt);
	if (and_l < or_l)
		*dst = and_pt;
	else
		*dst = or_pt;
}

int	get_next_index(int last, t_string_token **instructions_arr)
{
	t_emt	to_search;

	to_search = AND;
	if (last == -1)
		return (0);
	if (g_ret_val != 0)
		to_search = OR;
	while (instructions_arr[last] && instructions_arr[last]->token != to_search)
		string_token_destructor(instructions_arr[last++]);
	if (instructions_arr[last])
		return (last);
	return (-1);
}
