/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:21 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:32:43 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_plane	*plane(void)
{
	t_plane	*plane;

	plane = (t_plane *)calloc(1, sizeof(t_plane));
	if (!plane)
	{
		printf("Error: plane: calloc failed\n");
		return (NULL);
	}
	shape(PLANE, &(plane->shape));
	plane->shape.local_intersect = intersect_plane;
	plane->shape.local_normal_at = plane_normal_at;
	plane->shape.local_print = print_plane;
	plane->shape.local_free = free_plane;
	return (plane);
}

t_tuple *calculate_axis(double dot_product, t_tuple* object_normal, const t_tuple normal, double* rotation_angle) 
{
	t_tuple* axis;

	axis = NULL;
	if (dot_product == -1) 
	{
		*rotation_angle = M_PI;
		axis = vector(0, 0, 1);
		return axis;
	}
	*rotation_angle = acos(dot_product);
	axis = cross(*object_normal, normal);

	return axis;
}

t_matrix	*find_rotation_matrix(const t_tuple normal)
{
	t_matrix	*rotate;
	t_tuple		*object_normal;
	t_tuple		*axis;
	double		dot_product;
	double		rotation_angle;

	object_normal = vector(0, 1, 0);
	dot_product = dot(*object_normal, normal);
	if (dot_product == 1)
	{
		free(object_normal);
		return (identity(4));
	}
	axis = calculate_axis(dot_product, object_normal, normal, &rotation_angle);
	rotate = rotation_matrix(rotation_angle, axis->x, axis->y, axis->z);
	free_tuples(&object_normal, &axis, NULL);
	return (rotate);
}

void	free_plane(void *p)
{
	t_plane	*plane;

	plane = (t_plane *)p;
	if (!plane)
		return ;
	free(plane);
}
