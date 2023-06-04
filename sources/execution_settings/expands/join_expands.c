/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_expands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:39:11 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 19:22:35 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	_expand_lines(char **str_arr, char **env);
static void				_remove_quotes(char **str_arr);

/*----------------------------------------------------------------------------*/

t_return_status	join_arr_on(char **str_arr, char **line_pt, char **env)
{
	*line_pt = NULL;
	if (_expand_lines(str_arr, env) != SUCCESS)
		return (ft_free_split(str_arr), FAILED_MALLOC);
	_remove_quotes(str_arr);
	if (ft_join_str_arr_on(str_arr, line_pt) != SUCCESS)
		return (ft_free_split(str_arr), FAILED_MALLOC);
	return (ft_free_split(str_arr), SUCCESS);
}

static t_return_status	_expand_lines(char **str_arr, char **env)
{
	while (*str_arr)
	{
		if (**str_arr == '$' \
			&& replace_dollar_str_by_env_value(str_arr, env) != SUCCESS)
			return (FAILED_MALLOC);
		else if (**str_arr == - '"' \
			&& replace_dquotes_str_by_env_value(str_arr, env) != SUCCESS)
			return (FAILED_MALLOC);
		str_arr++;
	}
	return (SUCCESS);
}

void	cpy_next_char(unsigned int index, char *str)
{
	(void)index;
	*str = *(str + 1);
	if (*str == - '\'' || *str == - '"')
		*str = 0;
}

static void	_remove_quotes(char **str_arr)
{
	const char	quotes_arr[] = {(- '\''), - '"', 0};

	while (*str_arr)
	{
		if (is_from(**str_arr, (char *)quotes_arr))
			ft_striteri(*str_arr, &cpy_next_char);
		str_arr++;
	}
}
