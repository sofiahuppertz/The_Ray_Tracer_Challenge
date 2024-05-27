#include "scene.h"

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
	set_material(&cy->c.shape, materialcpy(*_scene->material));
	rotate = find_rotation_matrix(*c.axis);
	set_bounds(&cy->c, -c.height / 2.0, c.height / 2.0);
	set_closed(&cy->c, 1);
	radius = c.diameter / 2.0;
	transform(&cy->c.shape, chain_tfs(translation(c.center->x, c.center->y,
				c.center->z), rotate, scaling(radius, 1, radius), NULL));
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