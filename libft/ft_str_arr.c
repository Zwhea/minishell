/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:59:33 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/10 01:59:34 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**_ft_str_array_dup_ep(char **str_arr, size_t i);

size_t	ft_str_array_len(char **str_arr)
{
	size_t	i;

	i = 0;
	while (*str_arr)
	{
		str_arr++;
		i++;
	}
	return (i);
}

char	**ft_str_array_dup(char **str_arr)
{
	char	**new;
	size_t	i;

	new = malloc(sizeof(char *) * (ft_str_array_len(str_arr) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (*str_arr)
	{
		new[i] = ft_strdup(*str_arr);
		if (new[i] == NULL)
			return (_ft_str_array_dup_ep(new, ++i));
		i++;
		str_arr++;
	}
	new[i] = NULL;
	return (new);
}

static char	**_ft_str_array_dup_ep(char **str_arr, size_t i)
{
	while (i--)
		free(str_arr[i]);
	free(str_arr);
	return (NULL);
}

char	**ft_strarray_join(char **first, char **second)
{
	char	**new;
	char	**pin;

	new = malloc(sizeof(char *) * (ft_str_array_len(first) \
			+ ft_str_array_len(second) + 1));
	if (new == NULL)
		return (NULL);
	pin = new;
	while (*first)
		*(pin++) = *(first++);
	while (*second)
		*(pin++) = *(second++);
	*pin = NULL;
	return (new);
}
