/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:58:30 by twang             #+#    #+#             */
/*   Updated: 2023/05/10 02:05:00 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		_cpy_content_in_s_join(char *s_join, char *s1, char *s2);
static size_t	s_length(char *s1, char *s2);

char	*strjoin_path_cmd(char *s1, char *s2)
{
	size_t	length;
	char	*s_join;

	if (!s1 || !s2)
		return (perror("strjoin_path_cmd"), free(s1), NULL);
	length = s_length((char *)s1, (char *)s2);
	s_join = ft_calloc(length + 1, sizeof(char));
	if (!s_join)
		return (free(s1), perror("strjoin_path_cmd"), NULL);
	_cpy_content_in_s_join(s_join, s1, s2);
	return (s_join);
}

static void	_cpy_content_in_s_join(char *s_join, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s_join[i + j] = s2[j];
		j++;
	}
	free(s1);
}

static size_t	s_length(char *s1, char *s2)
{
	size_t	join_length;
	size_t	s1_length;
	size_t	s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	join_length = s1_length + s2_length;
	return (join_length);
}
