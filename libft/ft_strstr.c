/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:57:22 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/06/02 15:07:34 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	while (*big)
	{
		if (ft_strncmp(big, little, ft_strlen(little)))
			return (big);
		big++;
	}
	return (NULL);
}
