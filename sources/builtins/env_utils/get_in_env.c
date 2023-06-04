/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:01:58 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/17 16:42:24 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line_from_key(char *key, char **env)
{
	char	**pin;
	size_t	ln;

	pin = env;
	ln = ft_strlen(key);
	while (*pin)
	{
		if (ft_strncmp(*pin, key, ln) == 0 \
			&& ((*pin)[ln] == 0 || (*pin)[ln] == '='))
			return (*pin);
		pin++;
	}
	return (*pin);
}

char	**get_line_addr_from_key(char *key, char **env)
{
	char	**pin;
	size_t	ln;

	pin = env;
	ln = ft_strlen(key);
	while (*pin)
	{
		if (ft_strncmp(*pin, key, ln) == 0 \
			&& ((*pin)[ln] == 0 || (*pin)[ln] == '='))
			return (pin);
		pin++;
	}
	return (pin);
}

char	*get_env_content_from_key(char *key, char **env)
{
	char	*line;
	char	*ret_val;

	line = get_line_from_key(key, env);
	if (line == NULL)
		return (NULL);
	ret_val = ft_strchr(line, '=');
	if (ret_val)
		return (ret_val + 1);
	return (NULL);
}

bool	key_is_not_alnum(char *line)
{
	if (*line == '=' || ft_isdigit(*line))
		return (true);
	while (*line != '=' && *line)
	{
		if (*line == '+' && *(line + 1) == '=')
			return (false);
		if (ft_isalnum(*line) == false && *line != '_')
			return (true);
		line++;
	}
	return (false);
}
