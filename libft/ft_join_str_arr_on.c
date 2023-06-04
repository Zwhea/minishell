/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_str_arr_on.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:04:26 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/16 14:54:00 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_return_status	ft_join_str_arr_on(char **str_arr, char **line_pt)
{
	char	**arr_pin;
	char	*str_pin;
	size_t	size_str;

	arr_pin = str_arr;
	size_str = 1;
	while (*arr_pin)
		size_str += ft_strlen(*(arr_pin++));
	*line_pt = malloc(size_str);
	if (*line_pt == NULL)
		return (FAILED_MALLOC);
	str_pin = *line_pt;
	arr_pin = str_arr;
	while (*arr_pin)
		str_pin = ft_strcpy_rn(str_pin, *(arr_pin++));
	return (SUCCESS);
}
