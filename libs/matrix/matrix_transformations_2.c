/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:20:14 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/27 14:39:27 by sofia            ###   ########.fr       */
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

t_matrix	*rotation_matrix(double angle, double x, double y, double z)
{
	t_matrix	*r;
	double		costheta;
	double		sintheta;
	double		oneminuscos;
	double		length;

	r = identity(4);
	if (!r)
		return (NULL);
	costheta = cos(angle);
	sintheta = sin(angle);
	oneminuscos = 1 - costheta;
	length = sqrt(x * x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
	r->m[0][0] = (x * x * oneminuscos) + costheta;
	r->m[0][1] = (x * y * oneminuscos) - (z * sintheta);
	r->m[0][2] = (x * z * oneminuscos) + (y * sintheta);
	r->m[1][0] = (y * x * oneminuscos) + (z * sintheta);
	r->m[1][1] = (y * y * oneminuscos) + costheta;
	r->m[1][2] = (y * z * oneminuscos) - (x * sintheta);
	r->m[2][0] = (z * x * oneminuscos) - (y * sintheta);
	r->m[2][1] = (z * y * oneminuscos) + (x * sintheta);
	r->m[2][2] = (z * z * oneminuscos) + costheta;
	return (r);
}

void	transform(void *elem, t_matrix *transformation)
{
	t_tf	*tf;

	if (!elem || !transformation)
	{
		printf("Error: transform: couldn't perform transformation: null arguments.\n");
		free_matrix(&transformation);
		return ;
	}
	tf = (t_tf *)elem;
	tf->transform(elem, transformation);
}
