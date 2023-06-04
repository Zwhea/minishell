/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:06:15 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 19:23:40 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_increment_till_true(t_increment_ft increment_ft, \
								void *arg, char **line_pt);

/*----------------------------------------------------------------------------*/

void	increment_count_and_reset_pin(size_t *count_pt, char **line_pt)
{
	const char	char_arr[4] = {'$', - '\'', - '"', '\0'};

	(*count_pt)++;
	if (**line_pt == - '"')
		_increment_till_true(&is_eq_to, (void *)- '"', line_pt);
	else if (**line_pt == '$' && *(*line_pt + 1) == '?')
		*line_pt += 2;
	else if (**line_pt == - '\'')
		_increment_till_true(&is_eq_to, (void *)- '\'', line_pt);
	else if (**line_pt == '$')
		_increment_till_true(&isnotalnum, NULL, line_pt);
	else
		_increment_till_true(&is_from_base, (void *)char_arr, line_pt);
}

static void	_increment_till_true(t_increment_ft increment_ft, \
								void *arg, char **line_pt)
{
	(*line_pt)++;
	while (**line_pt && (*increment_ft)(**line_pt, arg) == false)
		(*line_pt)++;
	if (increment_ft == &is_eq_to && (**line_pt))
		(*line_pt)++;
}
