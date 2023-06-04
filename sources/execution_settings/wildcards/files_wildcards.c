/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:05:17 by twang             #+#    #+#             */
/*   Updated: 2023/05/30 14:36:03 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static int				_check_nb_of_match(char *line);
static t_return_status	_get_wildcard_file(char **line_pt);

/*----------------------------------------------------------------------------*/

t_return_status	wildcard_files(t_data *data, char **file, int block_id)
{
	int	match;

	match = 0;
	if (check_line(*file) != SUCCESS)
		return (SUCCESS);
	match = _check_nb_of_match(*file);
	if (match == -1)
		return (FAILURE);
	if (match == 0)
	{
		replace_wild_card(*file);
		return (SUCCESS);
	}
	if (match > 1)
	{
		replace_wild_card(*file);
		data->cmds_block[block_id].is_ambiguous = true;
		ft_dprintf(2, "minishell: %s: ambiguous redirect\n", *file);
		return (FAILURE);
	}
	return (_get_wildcard_file(file));
}

static int	_check_nb_of_match(char *line)
{
	struct dirent	*data;
	DIR				*directory;
	int				size;

	size = 0;
	directory = opendir(".");
	if (!directory)
	{
		perror ("minishell: opendir: cannot open current directory");
		return (-1);
	}
	while (1)
	{
		data = readdir(directory);
		if (data == NULL)
			break ;
		if (find_matching_files(line, data->d_name) == SUCCESS)
			size++;
	}
	closedir(directory);
	return (size);
}

static t_return_status	_get_wildcard_file(char **line_pt)
{
	struct dirent	*files;
	DIR				*directory;

	directory = opendir(".");
	if (!directory)
	{
		perror ("minishell: opendir: cannot open current directory");
		return (FAILURE);
	}
	while (1)
	{
		files = readdir(directory);
		if (files == NULL)
			break ;
		if (find_matching_files(*line_pt, files->d_name) == SUCCESS)
		{
			free(*line_pt);
			*line_pt = ft_strdup(files->d_name);
			if (*line_pt == NULL)
				return (perror("_get_wildcard_file"), FAILURE);
		}
	}
	closedir(directory);
	return (SUCCESS);
}
