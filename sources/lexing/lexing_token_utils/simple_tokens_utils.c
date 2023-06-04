/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_tokens_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:03:28 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 19:46:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	is_control_operator(t_emt token)
{
	if (token == PIPE || token == OR || token == AMPERSAND || token == AND)
		return (SUCCESS);
	return (FAILURE);
}
