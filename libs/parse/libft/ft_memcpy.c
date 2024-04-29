/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:04:38 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/11 17:44:33 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*#include <string.h>
int main () {
   char src[] = "Hello";
   char dest[20] = "hello world";

 printf("Before memcpy dest = %s\n", dest);
 memcpy(dest, src, sizeof(src));
 printf("After memcpy dest = %s\n", dest);
 ft_memcpy(dest, src, sizeof(src));
 printf("After ft_memcpy dest = %s\n", dest);
   
   return(0);
}*/
