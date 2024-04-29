/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:42:17 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:45:43 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dest))
		return (ft_strlen(src) + size);
	i = ft_strlen(dest);
	while (src[j] && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*#include <stdio.h>

int	main()
{
	char	dest[] = "Hello";
	const char	src[] = "World! good";

	printf("size trop petit, return slen + size: %ld\n", ft_strlcat(dest, src, 4));
	ft_strlcat(dest, src, 15);
	printf("size > dlen, return string copiee: %s\n", dest);
	return 0;
}*/
