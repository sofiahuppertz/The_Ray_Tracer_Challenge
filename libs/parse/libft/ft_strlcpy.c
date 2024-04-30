/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:30:47 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:45:59 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char src[] = "coucou";
	char dest[10];
	int corr = strlcpy(dest, src, 0);
	int me = ft_strlcpy(dest, src, 0);
	printf("corr: [%d] | me: [%d]\n", corr, me);
	return 0;
}*/
