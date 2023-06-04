/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_get_ft_to_do.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:14:18 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 16:48:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_export_ft	get_ft_to_do(char *line, char **env)
{
	char	*eq;
	char	*plus;

	eq = ft_strchr(line, '=');
	plus = ft_strchr(line, '+');
	get_rid_of_plus(line);
	if (key_is_not_alnum(line))
		return (&not_in_context_error);
	if (has_a_key_from_env(line, env) == false)
	{
		g_ret_val = 0;
		return (&add_str_to_env);
	}
	if (eq == NULL)
		return (&do_nothing_t_export_ft);
	if (plus == eq - 1)
		return (&concat_content_to_line_in_env);
	return (&replace_content_in_env_pt);
}

void	get_rid_of_plus(char *line)
{
	if (line == NULL)
		return ;
	while (*line != '=' && *line)
	{
		if (*line == '+')
		{
			ft_memmove(line, line + 1, ft_strlen(line));
			return ;
		}
		line++;
	}
}

t_return_status	concat_content_to_line_in_env(char *line, char ***env_pt)
{
	char	*content;
	char	**env_line;
	char	*tmp;

	content = ft_strchr(line, '=');
	*(content++) = 0;
	env_line = get_line_addr_from_key(line, *env_pt);
	tmp = *env_line;
	*env_line = ft_strjoin(*env_line, content);
	g_ret_val = 0;
	free(tmp);
	free(line);
	return (SUCCESS);
}

t_return_status	do_nothing_t_export_ft(char *line, char ***env_pt)
{
	(void)line;
	(void)env_pt;
	g_ret_val = 0;
	return (SUCCESS);
}

t_return_status	not_in_context_error(char *line, char ***env_pt)
{
	(void)env_pt;
	g_ret_val = 1;
	if (dprintf(2, "export : '%s': not a valid identifier\n", line) == -1)
		return (free(line), FAILED_WRITE);
	return (free(line), SUCCESS);
}
