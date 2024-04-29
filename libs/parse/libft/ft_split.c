/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:19:20 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:44:43 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			len++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

static char	*copystr(const char *original, char c)
{
	char	*copy;
	int		i;

	i = 0;
	if (!original)
		return (NULL);
	while (original[i] && original[i] != c)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (original[i] && original[i] != c)
	{
		copy[i] = original[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**ft_fill_tab(char const *s, char c, char **tab, int len_tab)
{
	int	i;

	i = 0;
	if (!s || !tab || !len_tab)
		return (NULL);
	while (i != len_tab)
	{
		while (*s && *s == c)
			s++;
		tab[i] = copystr(s, c);
		if (!tab[i])
		{
			i--;
			while (i >= 0)
				free(tab[i--]);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		len_tab;
	char	**tab;

	len_tab = countword(s, c);
	if (len_tab == 0)
	{
		tab = malloc(sizeof(char *));
		tab[0] = 0;
		return (tab);
	}
	if (!s)
		return (NULL);
	tab = malloc (sizeof(char *) * (len_tab + 1));
	if (!tab)
		return (NULL);
	return (ft_fill_tab(s, c, tab, len_tab));
}
