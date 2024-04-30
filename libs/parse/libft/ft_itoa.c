/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:38:45 by lchiu             #+#    #+#             */
/*   Updated: 2023/05/17 09:38:57 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += 1;
		return (count);
	}
	if (n < 0)
		count += 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign *= -1;
	return (sign);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nb;

	nb = n;
	len = ft_count(nb);
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	if (sign(n) < 0)
		nb *= -1;
	if (nb == 0)
		s[len] = nb + '0';
	while (nb != 0)
	{
		s[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign(n) < 0)
		s[len] = '-';
	return (s);
}
