#include "libs/librt.h"

int main(void)
{	
	t_plane *floor;
	t_plane *wall;
	t_sphere *middle;
	t_sphere *right;
	t_sphere *left;

	floor = plane();
	t_material *m = default_material();
	set_color(m, color(0.96863, 0.61961, 0.87843));
	set_material(&floor->shape, m);

	wall = plane();
	transform((void*)&wall->shape, chain_tfs(translation(0, 0, 10), rotation_x(PI/2), NULL));
	t_material *m1 = materialcpy(*m);
	print_material(*m1);
	set_pattern(m1, stripe(white(), colorcpy(*m1->color)));
	set_material(&wall->shape, m1);

	middle = sphere();
	transform((void*)&middle->shape, translation(-0.5, 1, 0.5));
	t_material *m2 = materialcpy(*m1);
	set_color(m2, color(0.58824, 0.98039, 0.41961));
	set_pattern(m2, stripe(colorcpy(*m2->color), white()));
	transform((void *)m2->pattern, chain_tfs(scaling(0.2, 0.2, 0.2), rotation_y(degrees_to_radians(45)) ,NULL));
	m2->diffuse = 0.8;
	m2->specular = 0.9;
	set_material(&middle->shape, m2);


	right = sphere();
	transform((void *)&right->shape, chain_tfs(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5), NULL));
	t_material *m3 = materialcpy(*m2);
	set_color(m3, color(0.52549, 0.76471, 1));
	set_pattern(m3, stripe(white(), colorcpy(*m3->color)));
	transform((void *)m3->pattern, chain_tfs(scaling(0.2, 0.2, 0.2), rotation_z(degrees_to_radians(90)) ,NULL));
	set_material(&right->shape, m3);

	left = sphere();
	transform((void *)&left->shape, chain_tfs(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33), NULL));
	t_material *m4 = materialcpy(*m2);
	set_color(m4, color(1, 0.76078, 0.19608));
	set_pattern(m4, stripe(colorcpy(*m4->color), white()));
	transform((void *)m4->pattern, chain_tfs(scaling(0.2, 0.2, 0.2), rotation_y(degrees_to_radians(90)) ,NULL));
	set_material(&left->shape, m4);

	t_point_light *light = point_light(color(1, 1, 1), point(-10, 8, -10));
	t_camera *cam = camera(10, 5, PI/3);
	transform( (void*)cam, view_transformation(point(-1.5, 1.5, -4.5), point(0, 1, 0), vector(0, 1, 0)));
	t_world *w = empty_world();
	set_light(w, light);
	set_shape(w, &floor->shape);
	set_shape(w, &wall->shape);
	set_shape(w,  &middle->shape);
	set_shape(w, &right->shape);
	set_shape(w,  &left->shape);

	t_canvas *canvas = render(cam, w);
	//display_image(canvas);

	free_camera(&cam);
	free_world(&w);
	free_canvas(canvas);
}