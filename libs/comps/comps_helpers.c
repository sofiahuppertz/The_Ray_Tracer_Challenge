/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:37 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 14:00:50 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comps.h"

static double	find_last_reflective_index(t_shape *containers)
{
	t_shape	*ptr;

	ptr = containers;
	while (ptr->container_next)
		ptr = ptr->container_next;
	return (ptr->material->refrac_index);
}

static void	find_shape_and_remove(t_shape **containers, t_shape *shape)
{
	t_shape	*curr;
	t_shape	*prev;

	prev = *containers;
	if (!prev)
	{
		*containers = shape;
		return ;
	}
	curr = prev;
	while (curr)
	{
		if (curr->id == shape->id)
		{
			if (curr == prev)
				*containers = curr->container_next;
			else
				prev->container_next = curr->container_next;
			curr->container_next = NULL;
			return ;
		}
		prev = curr;
		curr = curr->container_next;
	}
	prev->container_next = shape;
}

static void	empty_container(t_shape **containers)
{
	t_shape	*curr;
	t_shape	*next;

	curr = *containers;
	while (curr)
	{
		next = curr->container_next;
		curr->container_next = NULL;
		curr = next;
	}
	*containers = NULL;
}

void	get_refractive_indices(const t_intersection hit, t_intersection *xs,
		t_comps *comps)
{
	t_shape			*containers;
	t_intersection	*ptr;
	t_shape			*curr_shape;

	containers = NULL;
	ptr = xs;
	while (ptr)
	{
		curr_shape = (t_shape *)ptr->object_ptr;
		if (ptr->t == hit.t)
		{
			if (!containers)
				comps->n1 = 1.0;
			else
				comps->n1 = find_last_reflective_index(containers);
		}
		find_shape_and_remove(&containers, curr_shape);
		if (ptr->t == hit.t)
		{
			if (!containers)
				comps->n2 = 1.0;
			else
				comps->n2 = find_last_reflective_index(containers);
			break ;
		}
		ptr = ptr->next;
	}
	empty_container(&containers);
}
