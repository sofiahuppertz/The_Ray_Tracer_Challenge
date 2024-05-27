/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_model.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:20:01 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 15:34:46 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

static t_color	*calculate_effective_color(const t_material material,
		t_comps comps, const t_point_light light)
{
	t_light_calculation	w;

	w.temp = pattern_at_object(material.pattern, *comps.object_ptr,
			*comps.over_point);
	w.effective_color = shur_product(*w.temp, *(light.intensity));
	free(w.temp);
	w.temp = shur_product(*material.ambient_color, *w.effective_color);
	free(w.effective_color);
	return (w.temp);
}

static t_color	*calculate_ambient(t_color *effective_color, double ambient)
{
	return (scalar_color(*effective_color, ambient));
}

static void	calculate_diffuse_and_specular(t_light_calculation *w,
		const t_material material, t_comps comps, const t_point_light light)
{
	double	edotr;
	double	factor;
	t_tuple	*reflectv;

	w->diffuse = scalar_color(*w->effective_color, material.diffuse * w->ldotn);
	neg_tuple(w->lightv);
	reflectv = reflection(*w->lightv, *comps.normalv);
	edotr = dot(*reflectv, *comps.eyev);
	if (edotr > 0)
	{
		free(w->specular);
		factor = pow(edotr, material.shininess) * material.specular;
		w->specular = scalar_color(*(light.intensity), factor);
	}
	free_tuples(&w->lightv, &reflectv, NULL);
}

t_color	*lighting(const t_material material, t_comps comps,
		const t_point_light light, int in_shadow)
{
	t_light_calculation	w;

	w.effective_color = calculate_effective_color(material, comps, light);
	w.lightv = norm(sub_tuple(*light.position, *comps.over_point));
	w.ambient = calculate_ambient(w.effective_color, material.ambient);
	if (in_shadow)
	{
		free_tuples(&w.lightv, NULL);
		free(w.effective_color);
		return (w.ambient);
	}
	w.diffuse = black();
	w.specular = black();
	w.ldotn = dot(*w.lightv, *comps.normalv);
	if (w.ldotn >= 0)
	{
		calculate_diffuse_and_specular(&w, material, comps, light);
	}
	free(w.effective_color);
	w.final = add_colors(w.ambient, w.specular, w.diffuse, NULL);
	return (w.final);
}
