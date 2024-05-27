/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:47 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:42:59 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	set_material_cone(t_cone *co, t_scene *_scene, t_make_cylindrical c)
{
	set_material(&co->c.shape, materialcpy(*_scene->material));
	set_bounds(&co->c, -c.height, 0);
	set_closed(&co->c, 1);
}

void	transform_cone(t_cone *co, t_matrix *rotate, double radius,
	t_make_cylindrical c)
{
	transform(&co->c.shape, chain_tfs(translation(c.center->x, c.center->y,
				c.center->z), rotate, scaling(radius, 1, radius),
			translation(0, c.height / 2.0, 0), NULL));
}

void	make_cone(t_make_cylindrical c, t_attributes *attributes, ...)
{
	t_scene		*_scene;
	t_matrix	*rotate;
	t_cone		*co;
	double		radius;
	va_list		extras;

	_scene = scene();
	if (!_scene || !c.center || !c.axis || !c.color)
		return ;
	co = cone();
	if (!co)
		return ;
	rotate = find_rotation_matrix(*c.axis);
	radius = c.diameter / 2.0;
	set_pattern(co->c.shape.material, solid(c.color));
	set_material_cone(co, _scene, c);
	transform_cone(co, rotate, radius, c);
	if (attributes)
	{
		va_start(extras, attributes);
		set_extras(&co->c.shape, attributes, extras);
		va_end(extras);
	}
	set_shape(_scene->world, (t_shape *)&co->c);
	free_tuples(&c.center, &c.axis, NULL);
}
