/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:37 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 11:21:12 by sofia            ###   ########.fr       */
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

void process_intersection(t_intersection* ptr, const t_intersection hit, t_shape** containers, t_comps* comps) 
{
	t_shape* curr_shape;
	
	curr_shape = (t_shape*)ptr->object_ptr;
	if (ptr->t == hit.t) 
	{
		if (!*containers)
			comps->n1 = 1.0;
		else
			comps->n1 = find_last_reflective_index(*containers);
	}
	find_shape_and_remove(containers, curr_shape);
	if (ptr->t == hit.t) 
	{
		if (!*containers)
			comps->n2 = 1.0;
		else
			comps->n2 = find_last_reflective_index(*containers);
	}
}

void get_refractive_indices(const t_intersection hit, t_intersection* xs, t_comps* comps) 
{
	t_shape *containers;
	t_intersection *ptr;

	containers = NULL;
	ptr = xs;
	while (ptr) 
	{
		process_intersection(ptr, hit, &containers, comps);
		if (ptr->t == hit.t)
			break;
		ptr = ptr->next;
	}
	empty_container(&containers);
}
