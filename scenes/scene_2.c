#include "libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(point(0, -2, -10), point(0, 0, 1), degrees_to_radians(40));
	make_ambient_light(0.2, color(1, 1, 1));
	make_light(point(-2, -2, -10), 0.9, color(div_255(255), div_255(215), div_255(168)));

	make_plane(point(0, 2, 0), vector(0, 1, 0), color(div_255(250), div_255(189), div_255(65)));
	make_cone(point(-2, 1, 0), vector(0, -1, 0), 1, 0.5, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(0, 1, -1), vector(0, -1, 0), 1, 0.5, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(-2.3, 1, 1), vector(0, -1, 0), 1, 0.5, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(-1.5, 1, -3), vector(0, 1, 0), 0.3, 1.5, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(0.5, 1, -2), vector(0, -1, 0), 0.25, 2, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(1, 1, -3), vector(0, 1, 0), 0.25, 1, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(1, 0, -3), vector(0, -1, 0), 0.25, 1, color(div_255(255), div_255(255), div_255(255)));

	make_plane(point(0, -2.1, 0), norm(vector(0, 1, 0)), color(div_255(250), div_255(189), div_255(65)));
	make_cone(point(-1, -2, -5), vector(0, 1, 0), 0.25, 2, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(1.6, -2, -4.2), vector(0, 1, 0), 0.33, 2.1, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(1.6, -0.5, -4.2), vector(0, -1, 0), 0.13, 1, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(0, -2, -3.5), vector(0, 1, 0), 1, 0.7, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(-0.3, -2, -3.5), vector(0, 1, 0), 0.4, 1.6, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(0.5, -2, -3.5), vector(0, 1, 0), 0.75, 0.8, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(0.5, -2, -7.5), vector(0, 1, 0), 0.2, 1.3, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(0.4, -2, -7.5), vector(0, 1, 0), 0.2, 0.7, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(-0.5, -2, -7.5), vector(0, 1, 0), 0.2, 1.1, color(div_255(255), div_255(255), div_255(255)));
	make_cone(point(-0.4, -2, -7.5), vector(0, 1, 0), 0.2, 0.7, color(div_255(255), div_255(255), div_255(255)));

	_scene->canvas = render(_scene->camera, _scene->world);
	printf("done\n");
	display_image(_scene->canvas);
}