/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:55:58 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:57:31 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	*sub_tuple(const t_tuple a, const t_tuple b)
{
	t_tuple	*diff;

	diff = tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	if (!diff)
	{
		printf("Error: sub_tuple: operation failed.\n");
		return (NULL);
	}
	if (diff->tf.type == IDK)
		printf("Warning: sub_tuple points to vector.\n");
	return (diff);
}

t_tuple	*neg_tuple(t_tuple *neg)
{
	if (!neg)
	{
		printf("Error: neg_tuple: null pointer.\n");
		return (NULL);
	}
	neg->x = -neg->x;
	neg->y = -neg->y;
	neg->z = -neg->z;
	neg->w = -neg->w;
	return (neg);
}

t_tuple	*scalar_tuple(t_tuple *a, const double scalar)
{
	if (!a)
	{
		printf("Error: scalar_tuple: null pointer.\n");
		return (NULL);
	}
	a->x *= scalar;
	a->y *= scalar;
	a->z *= scalar;
	a->w *= scalar;
	return (a);
}

double	mag(const t_tuple a)
{
	double	magnitude;

	magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
	return (magnitude);
}

t_tuple	*norm(t_tuple *a)
{
	double	m;

	if (!a)
	{
		printf("Error: norm: null pointer.\n");
		return (NULL);
	}
	m = mag(*a);
	scalar_tuple(a, 1 / m);
	if (!a)
		printf("Error: norm: operation failed.\n");
	return (a);
}
