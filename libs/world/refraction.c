/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:29:59 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:55:43 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_ray	*find_refracted_ray(const t_comps comps, double n_ratio,
		double cos_i, double sin2_t)
{
	t_ray	*refracted_ray;
	t_tuple	*direction;
	t_tuple	*temp[2];
	double	cos_t;

	cos_t = sqrt(1.0 - sin2_t);
	temp[0] = scalar_tuple(tuplecpy(*comps.normalv), n_ratio * cos_i - cos_t);
	temp[1] = scalar_tuple(tuplecpy(*comps.eyev), n_ratio);
	direction = sub_tuple(*temp[0], *temp[1]);
	free_tuples(&temp[0], &temp[1], NULL);
	refracted_ray = ray(tuplecpy(*comps.under_point), direction);
	return (refracted_ray);
}

static t_color	*compute_refracted_color(const t_world w, t_shape *shape,
		t_ray *refracted_ray, int remaining)
{
	t_color	*final_color;
	t_color	*temp_color;

	temp_color = color_at(w, *refracted_ray, remaining - 1);
	final_color = scalar_color(*temp_color, shape->material->transparency);
	free(temp_color);
	free_ray(&refracted_ray);
	return (final_color);
}

t_color	*refracted_color(const t_world w, const t_comps comps, int remaining)
{
	t_shape	*shape;
	t_ray	*refracted_ray;
	double	n_ratio;
	double	cos_i;
	double	sin2_t;

	shape = (t_shape *)comps.object_ptr;
	// Check if the material is transparent,
		// if the recursion has reached its limit,
		// or if the conditions for total internal reflection are met
	if (shape->material->transparency == 0 || remaining == 0)
		return (black());
	n_ratio = comps.n1 / comps.n2;
	cos_i = dot(*comps.eyev, *comps.normalv);
	sin2_t = n_ratio * n_ratio * (1 - (cos_i * cos_i));
	if (sin2_t > 1)
		return (black());
	// Compute the refracted color
	refracted_ray = find_refracted_ray(comps, n_ratio, cos_i, sin2_t);
	return (compute_refracted_color(w, shape, refracted_ray, remaining));
}
