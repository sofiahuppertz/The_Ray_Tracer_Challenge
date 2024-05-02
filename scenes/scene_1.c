#include "../libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(point(-0.5, 0.6, -5), point(0, 0, 1), degrees_to_radians(40));
	make_ambient_light(0.2, color(1, 1, 1));
	make_light(point(-5, 5, -5), 0.9, color(1, 1, 1));
	make_plane(point(0, 0, 10), vector(-0.707107, 0, -0.707107), color(div_255(255), div_255(255), div_255(255)));
	make_plane(point(0, 0, 10), vector(0.707107, 0, -0.707107), color(div_255(255), div_255(255), div_255(255)));
	make_plane(point(0, -1, 0), norm(vector(0, 1, 0)), color(div_255(76.5), div_255(127), div_255(255)));
	make_sphere(point(-2, -0.5, 2), 1, color(div_255(255), div_255(51), div_255(51)));
	make_sphere(point(-0.5, 0, 3.5), 2, color(div_255(51), div_255(255), div_255(51)));
	make_sphere(point(-1, -0.6, 2), 0.8, color(div_255(255), div_255(255), div_255(51)));
	make_cylinder(point(1, -0.7, 0), vector(-0.196116, 0.980581, 0), 0.7, 1.5, color(div_255(255), div_255(0), div_255(127)));

	_scene->canvas = render(_scene->camera, _scene->world);
	display_image(_scene->canvas);
}