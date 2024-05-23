/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:10 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:48:46 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern	*stripe_pattern(t_color *a, t_color *b)
{
	t_pattern	*stripe;

	stripe = (t_pattern *)calloc(1, sizeof(t_pattern));
	if (!stripe)
	{
		printf("Error: stripe_pattern calloc failed.\n");
	}
	pattern(a, b, stripe);
	stripe->local_pattern = stripe_at;
	return (stripe);
}

t_color	*stripe_at(void *pattern, const t_tuple point)
{
	t_pattern	*stripe;

	stripe = (t_pattern *)pattern;
	if ((int)floor(point.x) % 2 == 0)
		return (colorcpy(*stripe->a));
	return (colorcpy(*stripe->b));
}
