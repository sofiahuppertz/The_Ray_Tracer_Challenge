/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:20:14 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/27 15:55:31 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*rotation_z(double rad)
{
	t_matrix	*rotation;

	rotation = identity(4);
	if (!rotation)
		return (NULL);
	rotation->m[0][0] = cos(rad);
	rotation->m[0][1] = -sin(rad);
	rotation->m[1][0] = sin(rad);
	rotation->m[1][1] = cos(rad);
	return (rotation);
}

t_matrix	*chain_tfs(t_matrix *initial, ...)
{
	va_list		args;
	t_matrix	*next_transform;
	t_matrix	*result;
	t_matrix	*temp;

	va_start(args, initial);
	result = initial;
	while (1)
	{
		next_transform = (t_matrix *)va_arg(args, t_matrix *);
		if (next_transform == NULL)
			break ;
		temp = mult_matrices(*result, *next_transform);
		free_matrix(&result);
		free_matrix(&next_transform);
		result = temp;
	}
	va_end(args);
	return (result);
}

static void calculate_rotation_matrix(t_matrix *r, t_rotation_matrix rm) 
{
	r->m[0][0] = (rm.x * rm.x * rm.oneminuscos) + rm.costheta;
	r->m[0][1] = (rm.x * rm.y * rm.oneminuscos) - (rm.z * rm.sintheta);
	r->m[0][2] = (rm.x * rm.z * rm.oneminuscos) + (rm.y * rm.sintheta);
	r->m[1][0] = (rm.y * rm.x * rm.oneminuscos) + (rm.z * rm.sintheta);
	r->m[1][1] = (rm.y * rm.y * rm.oneminuscos) + rm.costheta;
	r->m[1][2] = (rm.y * rm.z * rm.oneminuscos) - (rm.x * rm.sintheta);
	r->m[2][0] = (rm.z * rm.x * rm.oneminuscos) - (rm.y * rm.sintheta);
	r->m[2][1] = (rm.z * rm.y * rm.oneminuscos) + (rm.x * rm.sintheta);
	r->m[2][2] = (rm.z * rm.z * rm.oneminuscos) + rm.costheta;
}

t_matrix *rotation_matrix(double angle, double x, double y, double z) 
{
	t_matrix *r;
	t_rotation_matrix rm;

	r = identity(4);
	if (!r)
		return (NULL);
	rm.costheta = cos(angle);
	rm.sintheta = sin(angle);
	rm.oneminuscos = 1 - rm.costheta;
	rm.length = sqrt(x * x + y * y + z * z);
	rm.x = x / rm.length;
	rm.y = y / rm.length;
	rm.z = z / rm.length;
	calculate_rotation_matrix(r, rm);
	return (r);
}

void	transform(void *elem, t_matrix *transformation)
{
	t_tf	*tf;

	if (!elem || !transformation)
	{
		printf("Error: transform: couldn't perform\
			transformation: null arguments.\n");
		free_matrix(&transformation);
		return ;
	}
	tf = (t_tf *)elem;
	tf->transform(elem, transformation);
}
