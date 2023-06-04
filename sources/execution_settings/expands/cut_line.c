/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:24:33 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 19:18:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static size_t			_count_indep_words(char *line);
static	t_return_status	_alloc_each_cells(char *line, char **line_arr);
static size_t			_count_word_ln_reset_pin(char **line_pt);
static void				_increment_ln_reset_pin(t_increment_ft incr_ft, \
							size_t *ln_pt, char **line_pt, void *arg);

/*----------------------------------------------------------------------------*/

t_return_status	cut_line_on(char *line, char ***res_pt)
{
	char	**line_arr;

	*res_pt = NULL;
	line_arr = malloc(sizeof(char *) * (_count_indep_words(line) + 1));
	if (line_arr == NULL)
		return (perror("cut_line_on"), free(line), FAILED_MALLOC);
	if (_alloc_each_cells(line, line_arr) != SUCCESS)
		return (free(line), free(line_arr), FAILED_MALLOC);
	*res_pt = line_arr;
	return (free(line), SUCCESS);
}

static size_t	_count_indep_words(char *line)
{
	size_t	count;

	count = 1;
	while (*line)
		increment_count_and_reset_pin(&count, &line);
	return (count);
}

static	t_return_status	_alloc_each_cells(char *line, char **line_arr)
{
	size_t	arr_indx;
	size_t	count;
	char	*tmp;

	*line_arr = ft_strdup("");
	arr_indx = 1;
	while (*line)
	{
		tmp = line;
		count = _count_word_ln_reset_pin(&line);
		line_arr[arr_indx++] = ft_substr(tmp, 0, count);
	}
	line_arr[arr_indx] = NULL;
	return (check_allocations(line_arr, arr_indx));
}

static size_t	_count_word_ln_reset_pin(char **line_pt)
{
	const char	char_arr[4] = {'$', - '\'', - '"', '\0'};
	size_t		ln;

	ln = 0;
	if (**line_pt == - '"')
		_increment_ln_reset_pin(&is_eq_to, &ln, line_pt, (void *)- '"');
	else if (**line_pt == '$' && *(*line_pt + 1) == '?')
	{
		*line_pt += 2;
		ln = 2;
	}
	else if (**line_pt == - '\'')
		_increment_ln_reset_pin(&is_eq_to, &ln, line_pt, (void *)- '\'');
	else if (**line_pt == '$')
		_increment_ln_reset_pin(&isnotalnum, &ln, line_pt, NULL);
	else
		_increment_ln_reset_pin(&is_from_base, &ln, line_pt, (void *)char_arr);
	return (ln);
}

static void	_increment_ln_reset_pin(t_increment_ft incr_ft, \
							size_t *ln_pt, char **line_pt, void *arg)
{
	if (ft_isalnum(**line_pt) != true)
	{
		(*line_pt)++;
		(*ln_pt)++;
	}
	while (**line_pt && (*incr_ft)(**line_pt, arg) == false)
	{
		(*line_pt)++;
		(*ln_pt)++;
	}
	if (incr_ft == &is_eq_to)
	{
		(*line_pt)++;
		(*ln_pt)++;
	}
}
