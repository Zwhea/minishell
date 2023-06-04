/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:19:13 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/21 14:08:15 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_cpy_lst_in_str(t_list *lst, char *str);

t_return_status	ft_lststr_to_str(t_list *lst, char **str_pt)
{
	int		len;
	char	*str;

	len = ft_lststrlen(lst);
	str = malloc(len + 1);
	if (str == NULL)
		return (FAILED_MALLOC);
	_cpy_lst_in_str(lst, str);
	*str_pt = str;
	return (SUCCESS);
}

static void	_cpy_lst_in_str(t_list *lst, char *str)
{
	while (lst)
	{
		str = ft_strcpy_rn(str, lst->content);
		lst = lst->next;
	}
}

size_t	ft_lststrlen(t_list *lst)
{
	size_t	length;

	length = 0;
	while (lst)
	{
		length += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (length);
}
