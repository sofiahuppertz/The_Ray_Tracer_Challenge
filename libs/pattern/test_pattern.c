/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:13 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:49:14 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern	*test_pattern(void)
{
	t_pattern	*pat;

	pat = (t_pattern *)calloc(1, sizeof(t_pattern));
	if (!pat)
	{
		printf("Error: stripe_pattern calloc failed.\n");
	}
	pattern(black(), black(), pat);
	pat->local_pattern = test_pattern_at;
	return (pat);
}

t_color	*test_pattern_at(void *pattern, const t_tuple point)
{
	(void)pattern;
	return (color(point.x, point.y, point.z));
}
