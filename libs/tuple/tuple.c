/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:54 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:56:40 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	*tuple(const double x, const double y, const double z, const double w)
{
	t_tuple	*tuple;

	tuple = NULL;
	tuple = (t_tuple *)calloc(1, sizeof(t_tuple));
	if (!tuple)
	{
		printf("Error: tuple memory allocation failed.\n");
		return (NULL);
	}
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	if (w != 1.0 && w != 0.0)
		printf("Warning: tuple: not a point nor vector.\n");
	tupletype(tuple);
	tuple->tf.transform = transform_tuple;
	return (tuple);
}

t_tuple	*point(const double x, const double y, const double z)
{
	t_tuple	*point;

	point = tuple(x, y, z, 1.0);
	if (!point)
	{
		printf("Error: point memory allocation failed.\n");
		return (NULL);
	}
	return (point);
}

t_tuple	*vector(const double x, const double y, const double z)
{
	t_tuple	*vector;

	vector = tuple(x, y, z, 0.0);
	if (!vector)
	{
		printf("Error: vector memory allocation failed.\n");
		return (NULL);
	}
	return (vector);
}

int	equal(const double a, const double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

t_tuple	*add_tuple(const t_tuple a, const t_tuple b)
{
	t_tuple	*sum;

	sum = tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	if (!sum)
	{
		printf("Error: add_tuple memory allocation failed.\n");
		return (NULL);
	}
	if (sum->tf.type == IDK)
		printf("Warning: add_tuple two points.\n");
	return (sum);
}
