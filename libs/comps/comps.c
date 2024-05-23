/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:18:33 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 13:30:14 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comps.h"

t_comps	*prep_comps(const t_intersection hit, const t_ray r, t_intersection *xs)
{
	t_comps	*comps;

	comps = (t_comps *)calloc(sizeof(t_comps), 1);
	if (!comps)
	{
		printf("Error: prep_comps: calloc failed.\n");
		return (NULL);
	}
	comps->t = hit.t;
	comps->object = hit.object;
	comps->object_ptr = (t_shape *)hit.object_ptr;
	comps->point = position(r, comps->t);
	comps->eyev = neg_tuple(tuplecpy(*r.di));
	compute_normal(comps);
	compute_epsilon_boundaries(comps);
	comps->reflectv = reflection(*r.di, *comps->normalv);
	get_refractive_indices(hit, xs, comps);
	return (comps);
}

void	free_comps(t_comps **comps)
{
	t_comps	*ptr;

	ptr = *comps;
	free(ptr->point);
	free(ptr->eyev);
	free(ptr->normalv);
	free(ptr->over_point);
	free(ptr->under_point);
	free(ptr->reflectv);
	free(ptr);
	ptr = NULL;
	*comps = NULL;
}

void	print_comps(t_comps *comps)
{
	printf("t: %f\n", comps->t);
	printf("object: %d\n", comps->object);
	printf("object_ptr: %p\n", comps->object_ptr);
	printf("point: ");
	print_tuple(comps->point);
	printf("over_point: ");
	print_tuple(comps->over_point);
	printf("eyev: ");
	print_tuple(comps->eyev);
	printf("normalv: ");
	print_tuple(comps->normalv);
	printf("inside: %d\n", comps->inside);
}
