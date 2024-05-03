#include "libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();

	_scene->canvas = render(_scene->camera, _scene->world);
	make_plane(point(0, 0, 0), vector(0, 1, 0), color(1, 1, 1), rfl(0.4), checker(black(), white(), 1, 0), NULL);
	make_plane(point(0, 0, 0), vector(0, 1, 0), color(1, 1, 1), rfl(0.4), checker(black(), white(), 1, 0), NULL);
	make_plane(point(0, 0, 0), vector(0, 1, 0), color(1, 1, 1), rfl(0.4), checker(black(), white(), 1, 0), NULL);
	display_image(_scene->canvas);
}