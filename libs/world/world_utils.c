/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:30:06 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:55:12 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_sphere	*set(t_sphere *s1, t_sphere *s2, t_material *m, t_world *w)
{
	set_pattern(m, solid(color(0.8, 1.0, 0.6)));
	set_ambient(m, 0.1);
	set_diffuse(m, 0.7);
	set_specular(m, 0.2);
	set_shininess(m, 200.0);
	set_material(&s1->shape, m);
	s2 = sphere();
	if (!s2)
	{
		free_world(&w);
		return (NULL);
	}
	transform((void *)&s2->shape, scaling(0.5, 0.5, 0.5));
	set_shape(w, (t_shape *)&s1->shape);
	set_shape(w, (t_shape *)&s2->shape);
	return (s2);
}
