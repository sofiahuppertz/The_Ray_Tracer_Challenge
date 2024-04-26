#include "libs/librt.h"

int main(void)
{	
	t_plane *_plane;

	_plane = plane();
	t_material *m = default_material();
	
	set_material(&_plane->shape, m);
	t_pattern *p1 = stripe(color(0, 1, 0.), white());
	transform((void *)p1, rotation_y(degrees_to_radians(90)));
	t_pattern *p2 = stripe(white(), color(0, 0, 1));
	add_pattern(&p1, p2);
	t_pattern *blend = blended(p1);
	set_pattern(m, blend);


	t_point_light *light = point_light(color(1, 1, 1), point(-10, 8, -10));
	t_camera *cam = camera(100, 50, PI/3);
	transform( (void*)cam, view_transformation(point(0, 1, -5), point(0, 1, 0), vector(0, 1, 0)));
	t_world *w = empty_world();
	
	set_light(w, light);
	set_shape(w, &_plane->shape);


	t_canvas *canvas = render(cam, w);
	display_image(canvas);

	free_camera(&cam);
	free_world(&w);
	free_canvas(canvas);
}