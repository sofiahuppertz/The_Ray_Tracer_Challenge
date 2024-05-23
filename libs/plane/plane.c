/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:21 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:49:38 by lchiu            ###   ########.fr       */
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
	;
	plane->shape.local_print = print_plane;
	plane->shape.local_free = free_plane;
	return (plane);
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
	if (dot_product == -1)
	{
		rotation_angle = M_PI;
		axis = vector(0, 0, 1);
	}
	else
	{
		rotation_angle = acos(dot_product);
		axis = cross(*object_normal, normal);
	}
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
