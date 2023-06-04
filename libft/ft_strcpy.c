/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:57 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/15 18:41:11 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, char *src)
{
	char	*pin;

	pin = dst;
	while (*src)
	{
		*pin = *src;
		pin++;
		src++;
	}
	*pin = 0;
	return (dst);
}

char	*ft_strcpy_rn(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = *src;
	return (dst);
}
