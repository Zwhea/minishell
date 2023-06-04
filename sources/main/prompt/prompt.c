/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:06:23 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 16:09:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_get_alloc_box_on(char **box_pt, char **env);
static t_return_status	_get_alloc_line_prompt_on(char **line_pt, char **env);

/*----------------------------------------------------------------------------*/

t_return_status	get_prompt_on(char **prompt_pt, char **env)
{
	char	*line;
	char	*box;

	box = NULL;
	line = NULL;
	get_prompt(NULL, 2);
	*prompt_pt = NULL;
	if (_get_alloc_box_on(&box, env) != SUCCESS
		|| box == NULL
		|| _get_alloc_line_prompt_on(&line, env) != SUCCESS)
		return (free(box), free(line), SUCCESS);
	*prompt_pt = ft_strjoin(box, line);
	free(box);
	free(line);
	get_prompt(*prompt_pt, 1);
	return (SUCCESS);
}

static t_return_status	_get_alloc_box_on(char **box_pt, char **env)
{
	char	*box;
	char	*pwd;
	size_t	box_width;

	pwd = get_env_content_from_key("PWD", env);
	if (pwd == NULL)
		pwd = "We are kinda lost bitches.";
	box_width = (ft_strlen(pwd) + 4);
	box = malloc(ft_strlen(GREEN) + (box_width * 4 + 2) * \
					ft_strlen("\001\u2550\002") + box_width \
					+ 4 + ft_strlen("\001\u255D\002\n"END));
	if (box == NULL)
		return (perror("prompt"), FAILED_MALLOC);
	*box_pt = box;
	copy_all_box(box, pwd, box_width);
	return (SUCCESS);
}

static t_return_status	_get_alloc_line_prompt_on(char **line_pt, char **env)
{
	char	*line;
	char	*shlvl;
	char	*g_ret_str;

	shlvl = get_env_content_from_key("SHLVL", env);
	if (shlvl == NULL)
		shlvl = "At least THREE THOUSANDS";
	g_ret_str = ft_itoa(g_ret_val);
	if (g_ret_str == NULL)
		return (FAILED_MALLOC);
	line = malloc(ft_strlen(g_ret_str) + ft_strlen(shlvl) + \
					ft_strlen(PROMPT_MESSAGE) + 4);
	if (line == NULL)
		return (perror("prompt may seem not existing"), \
				free(g_ret_str), FAILED_MALLOC);
	*line_pt = line;
	line = ft_strcpy_rn(line, shlvl);
	line = ft_strcpy_rn(line, " : ");
	line = ft_strcpy_rn(line, g_ret_str);
	line = ft_strcpy_rn(line, PROMPT_MESSAGE);
	free(g_ret_str);
	return (SUCCESS);
}
