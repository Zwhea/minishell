/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:34:32 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 17:47:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static char	*_get_cmd_from_path(t_cmd *cmd, char **paths);

/*----------------------------------------------------------------------------*/

t_return_status	is_executable(char *command)
{
	struct stat	st;

	if (stat(command, &st) == 0)
	{
		if (!(st.st_mode & S_IXUSR))
		{
			ft_dprintf(2, "minishell: %s: Permission denied\n", command);
			g_ret_val = 126;
			return (FAILURE);
		}
		if (S_ISDIR(st.st_mode))
		{
			ft_dprintf(2, "minishell: %s: Is a directory\n", command);
			g_ret_val = 126;
			return (FAILURE);
		}
		return (SUCCESS);
	}
	g_ret_val = 127;
	ft_dprintf(2, "minishell: %s: No such file or directory\n", command);
	return (FAILURE);
}

void	close_this(int fd)
{
	if (fd > 2)
		close(fd);
}

char	*add_path_cmd(t_cmd *cmd, char **env)
{
	char	**paths;
	char	*str;

	if (cmd->id_command == EMPTY || cmd->commands[0] == NULL)
	{
		if (cmd->commands[0])
		{
			str = ft_strjoin(cmd->commands[0], " : command not found\n");
			g_ret_val = 127;
			if (str == NULL)
				return (perror("add path_cmd"), NULL);
			write(2, str, ft_strlen(str));
			free(str);
		}
		else
			g_ret_val = 0;
		return (NULL);
	}
	if (is_path(cmd->commands[0]))
		return (cmd->commands[0]);
	paths = get_paths(env);
	str = NULL;
	if (!paths)
		return (NULL);
	return (_get_cmd_from_path(cmd, paths));
}

static char	*_get_cmd_from_path(t_cmd *cmd, char **paths)
{
	int		i;
	char	*str;
	char	*ret_val;

	i = -1;
	while (paths[++i])
	{
		paths[i] = strjoin_path_cmd(paths[i], cmd->commands[0]);
		if (paths[i] == NULL)
			return (ft_free((void **)paths, ft_str_array_len(paths)), NULL);
		if (access(paths[i], X_OK) == 0)
		{
			ret_val = ft_strdup(paths[i]);
			ft_free((void **)paths, ft_str_array_len(paths));
			return (ret_val);
		}
	}
	g_ret_val = 127;
	ft_free((void **)paths, ft_str_array_len(paths));
	str = ft_strjoin(cmd->commands[0], " : command not found\n");
	if (str == NULL)
		return (NULL);
	write(2, str, ft_strlen(str));
	return (free(str), NULL);
}

void	free_all_others(t_cmd *cmds, int block_id, int nb_of_pipes)
{
	while (block_id++ < nb_of_pipes + 1)
	{
		ft_free_split(cmds[block_id].commands);
		free(cmds[block_id].heredoc_data);
	}
}
