/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:21:43 by twang             #+#    #+#             */
/*   Updated: 2023/06/02 15:08:43 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hayst;
	char	*needl;

	i = 0;
	hayst = (char *)haystack;
	needl = (char *)needle;
	if (!needl[i])
		return (hayst);
	while (i < len && hayst[i])
	{
		j = 0;
		while (hayst[i + j] == needl[j] && i + j < len)
		{
			if (needl[j + 1] == '\0')
				return ((char *) &hayst[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strstr_w(char *name, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!line[i])
		return (name);
	while (name[i])
	{
		j = 0;
		while (name[i + j] == line[j])
		{
			if ((line[j] == '\0' && name[i + j] == '\0') \
				|| line[j + 1] == - '*')
			{
				return ((char *) &name[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// char	*ft_strstr(const char *haystack, const char *needle)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	if (!needle[i])
// 		return ((char *)haystack);
// 	while (haystack[i])
// 	{
// 		j = 0;
// 		while (haystack[i + j] == needle[j])
// 		{
// 			if (needle[j] == '\0' && haystack[i + j] == '\0')
// 				return ((char *) &haystack[i]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

char	*ft_strstrr(char *haystack, char *needle)
{
	char	*tmp;
	char	*ret_val;

	ret_val = ft_strstr(haystack, needle);
	if (ret_val == NULL)
		return (NULL);
	tmp = ft_strstr(ret_val + 1, needle);
	while (tmp)
	{
		ret_val = tmp;
		tmp = ft_strstr(ret_val + 1, needle);
	}
	return (ret_val);
}
