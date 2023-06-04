/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:50:36 by twang             #+#    #+#             */
/*   Updated: 2023/05/29 15:01:06 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static int	find_path_in_environment(char **env);

/*----------------------------------------------------------------------------*/

char	**get_paths(char **env)
{
	int		i;
	int		find_path;
	char	**paths;

	find_path = find_path_in_environment(env);
	if (find_path == -1)
		return (NULL);
	paths = ft_split(&env[find_path][5], ':');
	if (!paths)
		return (perror("get_path spliting"), NULL);
	i = -1;
	while (paths[++i])
	{
		paths[i] = strjoin_path_cmd(paths[i], "/");
		if (!paths[i])
		{
			perror("paths error");
			ft_dprintf(2, "i = %d", i);
			ft_free_split_content(paths + i + 1);
			ft_free_split(paths);
			return (NULL);
		}
	}
	return (paths);
}

static int	find_path_in_environment(char **env)
{
	int	i;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (FAILURE);
	return (i);
}
