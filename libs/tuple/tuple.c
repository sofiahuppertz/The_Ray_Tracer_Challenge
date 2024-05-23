/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:54 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:54:13 by lchiu            ###   ########.fr       */
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
	return magnitude;
}

t_tuple	*norm(t_tuple *a)
{
	double	m;

	if (!a)
	{
		printf("Error: norm: null pointer.\n");
		return NULL;
	}
	m = mag(*a);
	scalar_tuple(a, 1 / m);
	if (!a)
		printf("Error: norm: operation failed.\n");
	return a;
}

double	dot(const t_tuple a, const t_tuple b)
{
	double	prod;

	if (a.w == 1.0 || b.w == 1.0)
		printf("Error: dot product: passing point  to vector operation.\n");
	prod = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return prod;
}

t_tuple	*cross(const t_tuple a, const t_tuple b)
{
	t_tuple	*prod;

	if (a.w == 1.0 || b.w == 1.0)
		printf("Error: cross product: passing point to vector operation.\n");
	prod = vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y
			* b.x);
	return prod;
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
	return dup;
}

t_tuple	*reflection(const t_tuple in, const t_tuple normal)
{
	t_tuple	*reflect;
	t_tuple	*temp;
	double	dot_product;

	dot_product = dot(in, normal);
	temp = tuplecpy(normal);
	scalar_tuple(temp, 2 * dot_product);
	reflect = sub_tuple(in, (const t_tuple)*temp);
	if (!reflect)
		printf("Error: reflection: operation failed.\n");
	free(temp);
	return reflect;
}

void	tupletype(t_tuple *a)
{
	if (a->w == 1.0)
		a->tf.type = POINT;
	else if (a->w == 0.0)
		a->tf.type = VECTOR;
	else
		a->tf.type = IDK;
	if (a->tf.type == IDK)
		print_tuple(a);
}

void	free_tuples(t_tuple **initial, ...)
{
	va_list args;
	t_tuple **t;

	va_start(args, initial);
	t = initial;
	while (t)
	{
		free(*t);
		t = NULL;
		t = (t_tuple **)va_arg(args, t_tuple **);
		if (!t || !*t)
			break ;
	}
	va_end(args);
}