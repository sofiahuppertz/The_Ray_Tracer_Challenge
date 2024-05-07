/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:26:54 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:58:15 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	len_str(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (s1[i] && ft_set(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (0);
	while (s1[i])
	{
		i++;
		count++;
	}
	i--;
	while (i > 0 && ft_set(s1[i], set))
	{
		i--;
		count--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	s = malloc(sizeof(char) * (len_str(s1, set) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i] && ft_set(s1[i], set))
		i++;
	while (j < len_str(s1, set))
	{
		s[j] = s1[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}
