/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:23:47 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/27 14:53:10 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	set_material_cy(t_make_cylindrical c, t_cylinder *cy, t_scene *_scene)
{
	set_material(&cy->c.shape, materialcpy(*_scene->material));
	set_bounds(&cy->c, -c.height / 2.0, c.height / 2.0);
	set_closed(&cy->c, 1);
}

void	transform_cy(t_make_cylindrical c, t_cylinder *cy, t_matrix *rotate,
	double radius)
{
	transform(&cy->c.shape, chain_tfs(translation(c.center->x, c.center->y,
				c.center->z), rotate, scaling(radius, 1, radius), NULL));
}

void	make_cylinder(t_make_cylindrical c, t_attributes *attributes, ...)
{
	t_scene		*_scene;
	t_cylinder	*cy;
	t_matrix	*rotate;
	double		radius;
	va_list		extras;

	_scene = scene();
	if (!_scene || !c.center || !c.axis || !c.color)
		return ;
	cy = cylinder();
	if (!cy)
		return ;
	rotate = find_rotation_matrix(*c.axis);
	set_material_cy(c, cy, _scene);
	radius = c.diameter / 2.0;
	transform_cy(c, cy, rotate, radius);
	set_pattern(cy->c.shape.material, solid(c.color));
	if (attributes)
	{
		va_start(extras, attributes);
		set_extras(&cy->c.shape, attributes, extras);
		va_end(extras);
	}
	set_shape(_scene->world, (t_shape *)&cy->c.shape);
	free_tuples(&c.axis, &c.center, NULL);
}
