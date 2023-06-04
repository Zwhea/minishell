/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:35:13 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/31 11:35:17 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_pt(void **first, void **second)
{
	void	*tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	ft_sort_arr(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 1;
		while (arr[i + j])
		{
			if (ft_strcmp_ign_maj(arr[i], arr[i + j]) > 0)
				ft_swap_pt((void **)&arr[i], (void **)&arr[i + j]);
			j++;
		}
		i++;
	}
}
