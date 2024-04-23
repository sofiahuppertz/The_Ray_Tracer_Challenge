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
	set_pattern(m1, stripe_pattern(m1->color, white()));
	set_material(&wall->shape, materialcpy(*m1));

	middle = sphere();
	transform((void*)&middle->shape, translation(-0.5, 1, 0.5));
	t_material *m2 = default_material();
	set_color(m2, color(0.58824, 0.98039, 0.41961));
	set_pattern(m2, stripe_pattern(white(), m2->color));
	//m2->diffuse = 0.7;
	//m2->specular = 0.3;
	set_material(&middle->shape, m2);

	right = sphere();
	transform((void *)&right->shape, chain_tfs(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5), NULL));
	t_material *m3 = materialcpy(*m2);
	set_color(m3, color(0.52549, 0.76471, 1));
	set_pattern(m3, stripe_pattern(white(), m3->color));
	set_material(&right->shape, m3);

	left = sphere();
	transform((void *)&left->shape, chain_tfs(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33), NULL));
	t_material *m4 = materialcpy(*m2);
	set_color(m4, color(1, 1, 0));
	set_pattern(m4, stripe_pattern(white(), m4->color));
	set_material(&left->shape, m4);

	t_point_light *light = point_light(color(1, 1, 1), point(-10, 8, -10));
	t_camera *cam = camera(100, 50, PI/3);
	transform( (void*)cam, view_transformation(point(-1.5, 1.5, -5), point(0, 1, 0), vector(0, 1, 0)));
	t_world *w = empty_world();
	set_light(w, light);
	set_shape(w, &floor->shape);
	set_shape(w, &wall->shape);
	set_shape(w,  &middle->shape);
	set_shape(w, &right->shape);
	set_shape(w,  &left->shape);

	//print_shapes(w->shapes);
	t_canvas *canvas = render(cam, w);
	display_image(canvas);

	free_camera(&cam);
	free_world(&w);
	free(canvas);
}