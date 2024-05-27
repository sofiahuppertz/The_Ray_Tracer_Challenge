/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:24:12 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:58:43 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	shape(t_elem type, t_shape *shape)
{
	static int	id;

	shape->id = id++;
	shape->tf.type = type;
	shape->tf.transform = set_transform;
	shape->material = default_material();
	if (!shape->material)
	{
		printf("Error: shape: default_material failed.\n");
		return ;
	}
	shape->tr = identity(4);
	if (!shape->tr)
	{
		printf("Error: shape: identity failed.\n");
		free(shape->material);
		return ;
	}
	shape->next = NULL;
	shape->container_next = NULL;
	shape->can_cast_shadow = 1;
}

void	set_transform(void *s, t_matrix *transformation)
{
	t_shape	*shape;

	shape = (t_shape *)s;
	if (!shape || !transformation)
	{
		printf("Error: set_transform: NULL pointer.\n");
		return ;
	}
	if (shape->tr)
		free_matrix(&shape->tr);
	shape->tr = transformation;
}

void	set_material(t_shape *shape, t_material *material)
{
	if (!shape || !material)
	{
		printf("Error: set_material: NULL pointer.\n");
		return ;
	}
	if (shape->material)
		free_material(&shape->material);
	shape->material = material;
}

void	free_shape(t_shape *shape_list)
{
	t_shape	*curr_shape;
	t_shape	*next_shape;

	curr_shape = shape_list;
	while (curr_shape)
	{
		next_shape = curr_shape->next;
		free_material(&curr_shape->material);
		free_matrix(&curr_shape->tr);
		curr_shape->local_free((void *)curr_shape);
		curr_shape = next_shape;
	}
}
