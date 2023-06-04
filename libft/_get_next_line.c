/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:54:46 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/21 14:08:15 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static t_return_status	_read_into_lst(int fd, t_list *head, char *buffer);
static t_return_status	_gnl_ep(t_list *head, t_return_status ert);

t_return_status	ft_lstnew_on(void *content, t_list **list_ptr)
{
	t_list	*new;

	new = malloc(sizeof (t_list));
	if (new == NULL)
		return (FAILED_MALLOC);
	new->content = content;
	new->next = NULL;
	*list_ptr = new;
	return (SUCCESS);
}

t_return_status	ft_lstnew_onsf(void *content, t_list **list_ptr)
{
	if (content == NULL)
		return (FAILED_MALLOC);
	return (ft_lstnew_on(content, list_ptr));
}

t_return_status	ft_gnl_on(int fd, char **line_pt)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_list		*head;

	if (ft_lstnew_onsf(ft_strdup(buffer), &head) != SUCCESS)
		return (ft_memcset(buffer, 0, 0, BUFFER_SIZE), FAILED_MALLOC);
	ft_memcset(buffer, 0, 0, BUFFER_SIZE);
	if (_read_into_lst(fd, head, buffer) != SUCCESS)
		return (_gnl_ep(head, FAILED_MALLOC));
	if (ft_lststr_to_str(head, line_pt) != SUCCESS)
		return (_gnl_ep(head, FAILED_MALLOC));
	if (**line_pt == 0)
	{
		free(*line_pt);
		*line_pt = NULL;
	}
	return (_gnl_ep(head, SUCCESS));
}

static t_return_status	_read_into_lst(int fd, t_list *head, char *buffer)
{
	t_list	*pin;
	char	*endl_pt;
	int		signal;

	pin = head;
	signal = BUFFER_SIZE;
	while (ft_strchr(pin->content, '\n') == NULL && signal == BUFFER_SIZE)
	{
		if (ft_lstnew_onsf(malloc(BUFFER_SIZE + 1), &(pin->next)) != SUCCESS)
			return (FAILED_MALLOC);
		pin = pin->next;
		signal = read(fd, pin->content, BUFFER_SIZE);
		if (signal == -1)
			return (FAILURE);
		((char *)(pin->content))[signal] = 0;
	}
	endl_pt = ft_strchr(pin->content, '\n');
	if (endl_pt)
	{
		ft_strcpy(buffer, endl_pt + 1);
		endl_pt[1] = 0;
	}
	return (SUCCESS);
}

static t_return_status	_gnl_ep(t_list *head, t_return_status ert)
{
	ft_lstclean(head, free);
	return (ert);
}
