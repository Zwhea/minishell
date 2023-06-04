/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:39:07 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/21 14:08:15 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_ustrdup(unsigned char *str)
{
	unsigned char	*new;
	size_t			size;

	size = ft_ustrlen(str);
	new = malloc(sizeof(unsigned char) * (size + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, str, size + 1);
	return (new);
}
//
//t_ert	ft_ustrdup_on(unsigned char *str, unsigned char **new_pt)
//{
//	size_t	size;
//
//	size = ft_ustrlen(str);
//	*new_pt = malloc(size + 1);
//	if (*new_pt == NULL)
//		return (FAILED_MALLOC);
//	ft_memcpy(*new_pt, str, size + 1);
//	return (SUCCESS);
//}
