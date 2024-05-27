/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:06 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 15:13:40 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_intersection	*intersect_world(const t_world w, const t_ray r)
{
	t_intersection	*xs;

	xs = intersect_shapes(w.shapes, r);
	return (xs);
}

t_color	*rfl_tsy_pos(const t_world w, const t_comps comps, int remaining,
	t_color *surface)
{
	double		reflectance;
	t_color		*reflected;
	t_color		*refracted;
	t_color		*reflected_frac;
	t_color		*refracted_frac;

	reflectance = schlick(comps);
	reflected = reflected_color(w, comps, remaining);
	refracted = refracted_color(w, comps, remaining);
	reflected_frac = scalar_color(*reflected, reflectance);
	free(reflected);
	refracted_frac = scalar_color(*refracted, 1 - reflectance);
	free(refracted);
	return (add_colors(surface, reflected_frac, refracted_frac, NULL));
}

t_color	*shade_hit(const t_world w, const t_comps comps, int remaining)
{
	t_material	*material;
	int			shadowed;
	t_color		*surface;

	material = ((t_shape *)(comps.object_ptr))->material;
	shadowed = is_shadowed(w, *comps.over_point);
	surface = lighting(*material, comps, *w.light, shadowed);
	if (material->reflective > 0 && material->transparency > 0)
		return (rfl_tsy_pos(w, comps, remaining, surface));
	return (add_colors(surface, reflected_color(w, comps, remaining),
			refracted_color(w, comps, remaining), NULL));
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
