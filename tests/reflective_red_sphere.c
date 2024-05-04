#include "libs/librt.h"

int main(void)
{	
	
	t_plane *floor;
	t_plane *left_wall;
	t_plane *right_wall;
	t_sphere *middle;

	floor = plane();
	t_material *m = default_material();
	m->reflective = 0.2;
	set_material(&floor->shape, m);
	transform((void *)floor, rotation_x(degrees_to_radians(2)));
	set_pattern(m, checker_pattern(white(), black()));

	left_wall = plane();
	transform((void *)left_wall, chain_tfs(translation(0, 0, 10), rotation_y(degrees_to_radians(-45)), rotation_x(degrees_to_radians(90)), NULL));
	t_material *m2 = default_material();
	set_pattern(m2, checker_pattern(white(), black()));
	set_material(&left_wall->shape, m2);


	right_wall = plane();
	transform((void *)right_wall, chain_tfs(translation(0, 0, 10), rotation_y(degrees_to_radians(45)), rotation_x(degrees_to_radians(90)),  NULL));
	t_material *m3 = default_material();
	set_pattern(m3, checker_pattern(white(), black()));
	set_material(&right_wall->shape, m3);


	middle = sphere();
	transform((void *)middle, translation(-1, 1, 0));
	t_material *m4 = default_material();
	m4->diffuse = 0.7;
	m4->reflective = 0.4;
	set_pattern(m4, solid(color(1, 0, 0)));
	set_material(&middle->shape, m4);

	t_point_light *light = point_light(color(1, 1, 1), point(0, 5, -10));
	t_camera *cam = camera(500, 250, PI/3);
	transform( (void*)cam, view_transformation(point(-1, 1.5, -5), point(0, 1, 0), vector(0, 1, 0)));

	t_world *w = empty_world();
	set_light(w, light);
	set_shape(w, &floor->shape);
	set_shape(w, &left_wall->shape);
	set_shape(w, &right_wall->shape);
	set_shape(w, &middle->shape);


	t_canvas *canvas = render(cam, w);
	display_image(canvas);

	free_camera(&cam);
	free_world(&w);
	free_canvas(canvas);
}