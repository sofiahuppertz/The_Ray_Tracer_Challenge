/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:06 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:55:12 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_intersection	*intersect_world(const t_world w, const t_ray r)
{
	t_intersection	*xs;

	xs = intersect_shapes(w.shapes, r);
	return (xs);
}

t_color	*shade_hit(const t_world w, const t_comps comps, int remaining)
{
	t_color		*surface;
	t_color		*reflected;
	t_color		*refracted;
	t_material	*material;
	double		reflectance;
	int			shadowed;
	t_color		*reflected_frac;
	t_color		*refracted_frac;

	material = NULL;
	material = ((t_shape *)(comps.object_ptr))->material;
	shadowed = is_shadowed(w, *comps.over_point);
	surface = lighting(*material, *comps.object_ptr, *w.light,
			*comps.over_point, *comps.eyev, *comps.normalv, shadowed);
	if (material->reflective > 0 && material->transparency > 0)
	{
		reflectance = schlick(comps);
		reflected = reflected_color(w, comps, remaining);
		refracted = refracted_color(w, comps, remaining);
		reflected_frac = scalar_color(*reflected, reflectance);
		free(reflected);
		refracted_frac = scalar_color(*refracted, 1 - reflectance);
		free(refracted);
		return (add_colors(surface, reflected_frac, refracted_frac, NULL));
	}
	reflected = reflected_color(w, comps, remaining);
	refracted = refracted_color(w, comps, remaining);
	return (add_colors(surface, reflected, refracted, NULL));
}

t_color	*color_at(const t_world w, const t_ray r, int remaining)
{
	t_intersection	*xs;
	t_intersection	*_hit;
	t_comps			*comps;
	t_color			*c;

	xs = intersect_world(w, r);
	_hit = hit(&xs);
	if (!_hit)
	{
		free_intersections(&xs);
		return (black());
	}
	comps = prep_comps(*_hit, r, xs);
	c = shade_hit(w, *comps, remaining);
	free_comps(&comps);
	free_intersections(&xs);
	return (c);
}
