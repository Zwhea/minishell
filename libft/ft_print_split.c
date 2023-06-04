/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:45:17 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/04/19 15:36:48 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_split(char **split)
{
	if (split == NULL)
	{
		printf("Null\n");
		return ;
	}
	while (*split)
	{
		if (write(1, "->", 2) == -1
			|| write(1, *split, ft_strlen(*split)) == -1
			|| write(1, "<-", 2) == -1
			|| write(1, "\n", 1) == -1)
			write(2, "Error write ft_print_split", 26);
		split++;
	}
	printf("%p\n", *split);
}

void	ft_eprint_split(char **split)
{
	if (split == NULL)
	{
		dprintf(2, "Null\n");
		return ;
	}
	while (*split)
	{
		if (write(2, *split, ft_strlen(*split)) == -1
			|| write(2, "\n", 1) == -1)
			write(2, "Error write ft_print_split", 26);
		split++;
	}
	dprintf(2, "%p\n", *split);
}
