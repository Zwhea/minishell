/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:43:42 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/30 15:39:44 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_string_token(t_string_token *token)
{
	const char	*msgarr[] = {"start", "|", "ifnot", "<", \
	">", "||", "&&", "<<", ">>", "lfpar", \
	")", ";", " ", "\t", "_ltr_", "newline", \
	"_str_", "dolrs", "file_", "hr_dt", "syner"};

	if (token->token == STRING)
		return (ft_strjoin(token->content, "'\n"));
	return (ft_strjoin(msgarr[token->token], "'\n"));
}
