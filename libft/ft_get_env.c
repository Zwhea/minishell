/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:57:50 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/10 01:57:51 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_env(char *str, char **env)
{
	while (*env)
	{
		if (ft_strncmp(str, *env, ft_strlen(str)) == 0
			&& ft_strchr(*env, '=') == *env + ft_strlen(str))
			return (ft_strdup(*env + ft_strlen(str) + 1));
		env++;
	}
	return (ft_strdup(""));
}
