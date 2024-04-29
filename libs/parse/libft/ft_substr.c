/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:36:18 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:58:58 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_null(char const *s, char *p, unsigned int start)
{
	if (ft_strlen(s) < start)
	{
		p = malloc(sizeof(char));
		p[0] = 0;
		return (p);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	p = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (p = ft_strdup("\0"));
	if (ft_strlen(s) < start)
		return (malloc_null(s, p, start));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
			p[j++] = s[i];
	}
	p[j] = '\0';
	return (p);
}
