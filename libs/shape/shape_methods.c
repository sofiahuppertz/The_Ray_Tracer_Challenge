/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:06 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:52:56 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	print_shapes(t_shape *shapes)
{
	t_shape	*curr_shape;

	curr_shape = shapes;
	while (curr_shape)
	{
		if (curr_shape->local_print)
			curr_shape->local_print((void *)curr_shape);
		curr_shape = curr_shape->next;
	}
}

// transform ray l.34
// check if shape is concrete l.39
// call local_intersect l.45
t_intersection	*intersect(const t_shape *shape, const t_ray ray, t_elem type)
{
	t_intersection	*xs;
	t_ray			*transformed_ray;

	xs = NULL;
	transformed_ray = raycpy(ray);
	if (!transformed_ray)
		return (NULL);
	transform((void *)transformed_ray, inverse(*shape->tr));
	if (type <= SHAPE)
	{
		printf("Interset: incorrect type.\n");
		return (NULL);
	}
	shape->local_intersect((void *)shape, *transformed_ray, &xs);
	free_ray(&transformed_ray);
	return (xs);
}

t_intersection	*intersect_shapes(t_shape *shapes, const t_ray ray)
{
	t_shape			*curr_shape;
	t_intersection	*tmp_xs;
	t_intersection	*final_xs;

	curr_shape = shapes;
	final_xs = NULL;
	tmp_xs = NULL;
	while (curr_shape)
	{
		tmp_xs = intersect(curr_shape, ray, curr_shape->tf.type);
		final_xs = merge_sorted(&final_xs, &tmp_xs);
		curr_shape = curr_shape->next;
	}
	return (final_xs);
}

// transform point to object space l.79
// call local_normal_at l.86
// transform normal by inverse of the transpose and normalize l.91
t_tuple	*normal_at(t_shape *shape, const t_tuple point)
{
	t_tuple		*normal;
	t_matrix	*tr;

	if (!shape)
	{
		printf("Error: normal_at: NULL pointer.\n");
		return (NULL);
	}
	transform((void *)&point, inverse(*shape->tr));
	if (shape->tf.type == SHAPE)
	{
		printf("Error: normal_at: abstract type.\n");
		return (NULL);
	}
	normal = NULL;
	shape->local_normal_at((void *)shape, point, &normal);
	if (!normal)
		return (NULL);
	tr = inverse(*shape->tr);
	transform((void *)normal, transpose(&tr));
	normal->w = 0;
	return (norm(normal));
}

t_color	*pattern_at_object(const t_pattern *pattern, const t_shape object,
		const t_tuple point)
{
	t_color	*res;

	if (!pattern || !pattern->local_pattern)
	{
		printf("Error: pattern_at_object : null ptr");
		return (NULL);
	}
	if (!object.tr)
	{
		printf("Error: pattern_at_object: NULL transform.\n");
		return (NULL);
	}
	transform((void *)&point, chain_tfs(inverse(*object.tr),
			inverse(*pattern->tr), NULL));
	res = pattern->local_pattern((void *)pattern, point);
	return (res);
}
