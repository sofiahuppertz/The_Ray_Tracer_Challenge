/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps_helpers_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:30:57 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 14:00:57 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comps.h"

void	compute_normal(t_comps *comps)
{
	comps->normalv = normal_at(comps->object_ptr, *comps->point);
	if (dot(*comps->normalv, *comps->eyev) < 0)
	{
		comps->inside = 1;
		neg_tuple(comps->normalv);
	}
	else
		comps->inside = 0;
}

void	compute_epsilon_boundaries(t_comps *comps)
{
	t_tuple	*normalv_cpy;

	normalv_cpy = tuplecpy(*comps->normalv);
	scalar_tuple(normalv_cpy, EPSILON);
	comps->over_point = add_tuple(*comps->point, *normalv_cpy);
	comps->under_point = sub_tuple(*comps->point, *normalv_cpy);
	free(normalv_cpy);
}
