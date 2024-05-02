#include "libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_ambient_light(_scene, 0.2, color(1, 1, 1));
	make_camera(_scene, point(0, -2, -10), point(0, 0, 1), degrees_to_radians(40));
	make_light(_scene, point(-2, -2, -10), 0.9, color(div_255(255), div_255(215), div_255(168)));

	make_plane(_scene, point(0, 2, 0), norm(vector(0, 1, 0)), color(div_255(250), div_255(189), div_255(65)));
	make_cone(_scene, point(-2, 1, 0), vector(0, -1, 0), 1, 0.5, white());
	make_cone(_scene, point(0, 1, -1), vector(0, -1, 0), 1, 0.5, white());
	make_cone(_scene, point(-2.3, 1, 1), vector(0, -1, 0), 1, 0.5, white());
	make_cone(_scene, point(-1.5, 1, -3), vector(0, 1, 0), 0.3, 1.5, white());
	make_cone(_scene, point(0.5, 1, -2), vector(0, -1, 0), 0.25, 2, white());
	make_cone(_scene, point(1, 1, -3), vector(0, 1, 0), 0.25, 1, white());
	make_cone(_scene, point(1, 0, -3), vector(0, -1, 0), 0.25, 1, white());

	make_plane(_scene, point(0, -2.1, 0), norm(vector(0, 1, 0)), color(div_255(250), div_255(189), div_255(65)));
	make_cone(_scene, point(-1, -2, -5), vector(0, 1, 0), 0.25, 2, white());
	make_cone(_scene, point(1.6, -2, -4.2), vector(0, 1, 0), 0.33, 2.1, white());
	make_cone(_scene, point(1.6, -0.5, -4.2), vector(0, -1, 0), 0.13, 1, white());
	make_cone(_scene, point(0, -2, -3.5), vector(0, 1, 0), 1, 0.7, white());
	make_cone(_scene, point(-0.3, -2, -3.5), vector(0, 1, 0), 0.4, 1.6, white());
	make_cone(_scene, point(0.5, -2, -3.5), vector(0, 1, 0), 0.75, 0.8, white());
	make_cone(_scene, point(0.5, -2, -7.5), vector(0, 1, 0), 0.2, 1.3, white());
	make_cone(_scene, point(0.4, -2, -7.5), vector(0, 1, 0), 0.2, 0.7, white());
	make_cone(_scene, point(-0.5, -2, -7.5), vector(0, 1, 0), 0.2, 1.1, white());
	make_cone(_scene, point(-0.4, -2, -7.5), vector(0, 1, 0), 0.2, 0.7, white());

	_scene->canvas = render(_scene->camera, _scene->world);
	display_image(_scene->canvas);
}