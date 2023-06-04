/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:00:19 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/29 18:20:21 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	has_a_key_from_env(char *line, char **env)
{
	bool	ret_val;
	char	*equal_sign;

	equal_sign = ft_strchr(line, '=');
	if (equal_sign == NULL)
		ret_val = is_a_key_from_env(line, env);
	else
	{
		*equal_sign = 0;
		ret_val = is_a_key_from_env(line, env);
		*equal_sign = '=';
	}
	return (ret_val);
}

bool	is_a_key_from_env(char *key, char **env)
{
	if (get_line_from_key(key, env) != NULL)
		return (true);
	return (false);
}

t_return_status	add_str_to_env(char *line, char ***env_pt)
{
	char	**new_env;
	char	**env;
	size_t	i;

	if (line == NULL)
		return (FAILURE);
	new_env = (char **)malloc(sizeof(char *) * (ft_str_array_len(*env_pt) + 2));
	if (new_env == NULL)
		return (perror("add str to env"), FAILED_MALLOC);
	env = *env_pt;
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[i++] = line;
	new_env[i++] = NULL;
	free(env);
	*env_pt = new_env;
	return (SUCCESS);
}

t_return_status	del_str_from_env(char *line, char ***env_pt)
{
	char	**new_env;
	char	**env;
	size_t	i;

	new_env = (char **)malloc(sizeof(char *) * (ft_str_array_len(*env_pt) + 1));
	if (new_env == NULL)
		return (perror("del_str_from_env"), FAILED_MALLOC);
	env = *env_pt;
	i = 0;
	while (*env)
	{
		if (*env != line)
			new_env[i++] = *env;
		env++;
	}
	free(line);
	new_env[i] = NULL;
	free(*env_pt);
	*env_pt = new_env;
	return (SUCCESS);
}

void	replace_content_in_env(char *line, char **env)
{
	char	**line_to_replace;

	*ft_strchr(line, '=') = 0;
	line_to_replace = get_line_addr_from_key(line, env);
	*ft_strchr(line, 0) = '=';
	free(*line_to_replace);
	*line_to_replace = line;
}
