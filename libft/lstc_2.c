/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstc_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:40:33 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/27 14:41:12 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lstc	*init_lstc_first_read(int fd)
{
	char	buffer[1];
	t_lstc	*new;

	if (read(fd, buffer, 1) != 1)
		return (NULL);
	new = malloc(sizeof(t_lstc));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->c = *buffer;
	return (new);
}

t_lstc	*lstc_clear(t_lstc *trash)
{
	t_lstc	*pin;

	while (trash->next)
	{
		pin = trash->next;
		free(trash);
		trash = pin;
	}
	free(trash);
	return (NULL);
}

t_lstc	*lstc_new(char c)
{
	t_lstc	*new;

	new = malloc(sizeof(t_lstc));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->c = c;
	return (new);
}

t_lstc	*read_lstc_from_fd(int fd)
{
	t_lstc	*lst;
	t_lstc	*tmp;
	char	buffer[1];
	int		signal;

	lst = init_lstc_first_read(fd);
	if (!lst)
		return (NULL);
	tmp = lst;
	signal = read(fd, buffer, 1);
	while (signal == 1)
	{
		tmp->next = lstc_new(*buffer);
		if (!tmp->next)
			return (lstc_clear(lst));
		tmp = tmp->next;
		signal = read(fd, buffer, 1);
	}
	if (signal == -1)
		return (lstc_clear(lst));
	return (lst);
}

void	lstc_cpy_in_str(t_lstc	*lst, char **str)
{
	char	*tmp;

	tmp = *str;
	while (lst)
	{
		*tmp++ = lst->c;
		lst = lst->next;
	}
	*tmp = 0;
}
