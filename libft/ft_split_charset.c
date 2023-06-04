/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:59:28 by twang             #+#    #+#             */
/*   Updated: 2023/05/10 20:31:31 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char *str, char *charset, int p)
{
	int	i;

	i = 0;
	while (charset[i] && charset[i] != str[p])
		i++;
	if (charset[i] == '\0')
		return (0);
	return (1);
}

static int	nb_word(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (is_sep(str, charset, i) && str[i] != '\0')
			i++;
		if (!is_sep(str, charset, i) && str[i] != '\0')
		{
			nb++;
			while (!is_sep(str, charset, i) && str[i] != '\0')
				i++;
		}
	}
	return (nb);
}

static int	len_word(char *str, char *charset, int w)
{
	int	i;
	int	nb;
	int	l;

	i = 0;
	nb = 0;
	l = 0;
	while (str[i])
	{
		while (is_sep(str, charset, i) && str[i] != '\0')
			i++;
		if (!is_sep(str, charset, i) && str[i] != '\0')
		{
			nb++;
			while (!is_sep(str, charset, i) && str[i] != '\0')
			{
				i++;
				if (nb == w)
					l++;
			}
		}
	}
	return (l);
}

static char	*cpy_word(char *str, char *charset, int w, int i)
{
	int		j;
	int		nb;
	char	*word;

	nb = 0;
	word = (char *)malloc((len_word(str, charset, w) + 1) * sizeof(char));
	while (str[i])
	{
		while (is_sep(str, charset, i) && str[i] != '\0')
			i++;
		if (!is_sep(str, charset, i) && str[i] != '\0')
		{
			nb++;
			j = 0;
			while (!is_sep(str, charset, i) && str[i] != '\0')
			{
				if (w == nb)
					word[j] = str[i];
				j++;
				i++;
			}
		}
	}
	word[len_word(str, charset, w)] = '\0';
	return (word);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		nbw;

	nbw = nb_word(str, charset);
	tab = (char **)malloc((nbw + 1) * sizeof(char *));
	i = -1;
	while (++i < nbw)
		tab[i] = cpy_word(str, charset, i + 1, 0);
	tab[i] = 0;
	return (tab);
}
