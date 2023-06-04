/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:17:26 by twang             #+#    #+#             */
/*   Updated: 2023/05/29 17:54:07 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_return_status	welcome_to_minihell(char ***env_pt)
{
	g_ret_val = 0;
	if (env_init_on(env_pt) != SUCCESS)
		return (FAILED_MALLOC);
	ft_dprintf(2, PURPLE"%s%s", START_MSG_00, START_MSG_01);
	ft_dprintf(2, "%s%s", START_MSG_02, START_MSG_03);
	ft_dprintf(2, "%s%s", START_MSG_04, START_MSG_05);
	ft_dprintf(2, "%s%s%s", START_MSG_06, START_MSG_07, START_MSG_08);
	ft_dprintf(2, "%s%s%s", START_MSG_09, START_MSG_10, START_MSG_11);
	ft_dprintf(2, "%s%s", START_MSG_12, START_MSG_13);
	ft_dprintf(2, "%s%s", START_MSG_00, START_MSG_01);
	ft_dprintf(2, ITALIC"%s"END, START_MSG_14);
	return (SUCCESS);
}
