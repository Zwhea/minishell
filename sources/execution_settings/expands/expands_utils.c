/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:02:58 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 19:19:18 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_eq_to(char obj, void *to_compare)
{
	if (obj == (char)(long long)to_compare)
		return (true);
	return (false);
}

bool	isnotalnum(char obj, void *to_ignore)
{
	(void)to_ignore;
	return (ft_isalnum(obj) == false && obj != '_');
}

bool	is_from_base(char obj, void *base)
{
	return (is_from(obj, (char *)base));
}

t_return_status	check_allocations(char **line_arr, size_t arr_len)
{
	int	tmp;

	tmp = arr_len;
	if (arr_len == 0)
		return (SUCCESS);
	while (arr_len--)
	{
		if (line_arr[arr_len] == NULL)
			break ;
		if (arr_len == 0)
			return (SUCCESS);
	}
	while (tmp--)
		free(line_arr[tmp]);
	perror("cut line");
	return (FAILED_MALLOC);
}
