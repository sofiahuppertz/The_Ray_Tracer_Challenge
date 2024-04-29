/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:41 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:46:31 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && !len)
		return (NULL);
	if (*find == '\0')
		return (((char *)str));
	while (str[i] && i < len)
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (find[j] && str[i + j] == find[j] && i + j < len)
				j++;
			if (find[j] == '\0')
				return (&((char *)str)[i]);
		}
		i++;
	}
	return (NULL);
}
