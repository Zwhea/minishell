/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:58:27 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 16:56:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_export_display(char **env);
static void				_display_unic_export(char *env_line);
t_export_ft				get_ft_to_do(char *line, char **env);

/*----------------------------------------------------------------------------*/

t_return_status	export_builtin(char **args, char ***env_pt)
{
	char		**tmp;

	if (ft_str_array_len(args) == 1)
		return (_export_display(*env_pt), SUCCESS);
	tmp = args + 1;
	while (*tmp != NULL)
	{
		if ((*get_ft_to_do(*tmp, *env_pt))(*tmp, env_pt) != SUCCESS)
			return (FAILED_MALLOC);
		tmp++;
	}
	return (g_ret_val);
}

t_return_status	replace_content_in_env_pt(char *line, char ***env_pt)
{
	return (replace_content_in_env(line, *env_pt), SUCCESS);
}

static t_return_status	_export_display(char **env)
{
	char	*line;

	line = get_first_line_in_env(env);
	while (line != NULL )
	{
		if (!(line[0] == '_' && line[1] == '='))
			_display_unic_export(line);
		line = get_next_line_in_env(line, env);
	}
	return (SUCCESS);
}

static void	_display_unic_export(char *env_line)
{
	char	*content;

	content = ft_strchr(env_line, '=');
	if (content == NULL)
	{
		printf("declare -x %s\n", env_line);
		return ;
	}
	*(content++) = 0;
	printf("declare -x %s=\"%s\"\n", env_line, content);
	*(--content) = '=';
}
