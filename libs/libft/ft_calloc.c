/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:45:40 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/18 12:24:05 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	nmemb_size;
	size_t	i;

	nmemb_size = nmemb * size;
	i = 0;
	if (nmemb == 0)
		return (malloc(0));
	if (nmemb == 0 || size == 0 || nmemb != nmemb_size / size)
		return (NULL);
	ptr = malloc(nmemb_size);
	if (!ptr)
		return (NULL);
	while (i < nmemb_size)
		ptr[i++] = 0;
	return (ptr);
}
