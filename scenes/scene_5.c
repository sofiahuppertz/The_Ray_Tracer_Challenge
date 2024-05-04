#include "libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(point(-0.5, 0.6, -5), point(0, 0, 1), degrees_to_radians(40));
	make_ambient_light(0.2, color(1, 1, 1));
	make_light(point(-5, 5, -5), 0.9, color(1, 1, 1));
	make_plane(point(0, 0, 10), vector(-0.707107, 0, -0.707107), color(div_255(181), div_255(228), div_255(255)), NULL);
	make_plane(point(0, 0, 10), vector(0.707107, 0, -0.707107), color(div_255(181), div_255(228), div_255(255)), NULL);
	make_plane(point(0, -1, 0), vector(0, 1, 0), color(div_255(181), div_255(228), div_255(255)), checker(white(), black()), rfl(0.2), NULL);
	make_sphere(point(1, -0.3, 2.2), 1.6, color(0, 0, 0), tsy(1.0), rfr(2.5), rfl(1.0), NULL);
	make_cylinder(point(-0.7, -0.3, 2.2),  norm(vector(1, 1, 0)), 0.7, 2.5, color(0, 0, 0),tsy(1.0), rfr(2.5), rfl(1.0), NULL);

	_scene->canvas = render(_scene->camera, _scene->world);
	display_image(_scene->canvas);
}