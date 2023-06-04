/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:22:34 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/15 20:48:31 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	int_arr_ret_min_indx(int *int_arr, size_t ln)
{
	size_t	indx_of_min;
	int		min;
	size_t	idx;

	indx_of_min = 0;
	min = *int_arr;
	idx = 1;
	while (--ln)
	{
		if (int_arr[idx] < min)
		{
			min = int_arr[idx];
			indx_of_min = idx;
		}
		idx++;
	}
	return (indx_of_min);
}

void	ft_int_array_set(int *tab, int value, size_t size)
{
	while (size--)
		tab[size] = value;
}
