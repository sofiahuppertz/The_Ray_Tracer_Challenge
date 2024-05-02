#include "../libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(_scene, point(-0.5, 0.6, -5), point(0, 0, 1), degrees_to_radians(40));
	make_ambient_light(_scene, 0.2, color(1, 1, 1));
	make_light(_scene, point(-5, 5, -5), 0.9, color(1, 1, 1));
	make_plane(_scene, point(0, 0, 10), vector(-0.707107, 0, -0.707107), color(1, 1, 1));
	make_plane(_scene, point(0, 0, 10), vector(0.707107, 0, -0.707107), color(1, 1, 1));
	make_plane(_scene, point(0, -1, 0), norm(vector(0, 1, 0)), color(0.3, 0.5, 1));
	make_sphere(_scene, point(-2, -0.5, 2), 1, color(1, 0.2, 0.2));
	make_sphere(_scene, point(-0.5, 0, 3.5), 2, color(0.2, 1, 0.2));
	make_sphere(_scene, point(-1, -0.6, 2), 0.8, color(1, 1, 0.2));
	make_cylinder(_scene, point(1, -0.7, 0), vector(-0.196116, 0.980581, 0), 0.7, 1.5, color(div_255(255), div_255(0), div_255(127)));

	_scene->canvas = render(_scene->camera, _scene->world);
	display_image(_scene->canvas);
}