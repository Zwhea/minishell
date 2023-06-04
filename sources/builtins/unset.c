/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:58:54 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/29 17:02:56 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_unset_builtin_ep(char *msg);
static void				_is_valid_identifier(char *str);

/*----------------------------------------------------------------------------*/

t_return_status	unset_builtin(char **args, char ***env_pt)
{
	char	**tmp;
	char	*line_to_del;

	tmp = args + 1;
	while (*tmp)
	{
		_is_valid_identifier(*tmp);
		if (ft_strchr(*tmp, '=') != NULL)
		{
			tmp++;
			continue ;
		}
		line_to_del = get_line_from_key(*tmp, *env_pt);
		if (line_to_del != NULL)
			if (del_str_from_env(line_to_del, env_pt))
				return (_unset_builtin_ep("unset: malloc_failed\n"));
		tmp++;
	}
	return (SUCCESS);
}

static t_return_status	_unset_builtin_ep(char *msg)
{
	ft_dprintf(2, "%s", msg);
	return (FAILED_MALLOC);
}

static void	_is_valid_identifier(char *str)
{
	bool	flag;
	char	*tmp;

	flag = false;
	tmp = str;
	while (*str)
	{
		if (ft_isalnum(*str) == false && *str != '_')
		{
			flag = true;
			break ;
		}
		str++;
	}
	if (flag)
	{
		g_ret_val = 1;
		ft_dprintf(2, \
		"minishell: unset: '%s': not a valid identifier\n", tmp);
	}
}
