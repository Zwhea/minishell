/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:03:33 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/21 18:25:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_arr(int **int_arr)
{
	int	**tmp;

	tmp = int_arr;
	while (*int_arr)
	{
		free(*int_arr);
		int_arr++;
	}
	free(tmp);
}
