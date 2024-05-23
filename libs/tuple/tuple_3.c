/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:57:12 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 15:00:12 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

double	dot(const t_tuple a, const t_tuple b)
{
	double	prod;

	if (a.w == 1.0 || b.w == 1.0)
		printf("Error: dot product: passing point  to vector operation.\n");
	prod = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (prod);
}

t_tuple	*cross(const t_tuple a, const t_tuple b)
{
	t_tuple	*prod;

	if (a.w == 1.0 || b.w == 1.0)
		printf("Error: cross product: passing point to vector operation.\n");
	prod = vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y
			* b.x);
	return (prod);
}

void	print_tuple(const t_tuple *a)
{
	printf("x: %f, y: %f, z: %f, w: %f\n", a->x, a->y, a->z, a->w);
}

t_tuple	*tuplecpy(const t_tuple a)
{
	t_tuple	*dup;

	dup = tuple(a.x, a.y, a.z, a.w);
	if (!dup)
		printf("Error: tuplecpy: operation failed.\n");
	return (dup);
}

t_tuple	*reflection(const t_tuple in, const t_tuple normal)
{
	t_tuple	*reflect;
	t_tuple	*temp;
	double	dot_product;

	dot_product = dot(in, normal);
	temp = tuplecpy(normal);
	scalar_tuple(temp, 2 * dot_product);
	reflect = sub_tuple(in, (const t_tuple) * temp);
	if (!reflect)
		printf("Error: reflection: operation failed.\n");
	free(temp);
	return (reflect);
}
