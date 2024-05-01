#include "libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(_scene, point(0, 0, -5), point(0, 0, 1), degrees_to_radians(40));
	make_ambient_light(_scene, 0.2, color(1, 1, 1));
	make_light(_scene, point(-5, 5, -5), 0.9, color(1, 1, 1));
	make_plane(_scene, point(0, -1, 0), norm(vector(0, 1, 0)), color(1, 1, 1));
	make_sphere(_scene, point(0, 0, 0), 2, color(1, 0, 0));

	_scene->canvas = render(_scene->camera, _scene->world);
	display_image(_scene->canvas);

}