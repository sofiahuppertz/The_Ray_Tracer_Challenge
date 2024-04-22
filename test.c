
#include "libs/librt.h"

int main(void)
{	
	t_sphere *floor;
	t_sphere *left_wall;
	t_sphere *right_wall;
	t_sphere *middle;
	t_sphere *right;
	t_sphere *left;

	floor = sphere();
	transform((void*)&floor->shape, scaling(10, 0.01, 10));
	t_material *m = default_material();
	set_material_color(m, color(1, 1, 1));
	m->specular = 0;
	set_material(&floor->shape, m);

	left_wall = sphere();
	transform((void*)&left_wall->shape, chain_tfs(translation(0, 0, 5), rotation_y(-PI/4), rotation_x(PI/2), scaling(10, 0.01, 10), NULL));
	set_material(&left_wall->shape, materialcpy(*m));

	right_wall = sphere();
	transform((void*)&right_wall->shape, chain_tfs(translation(0, 0, 5), rotation_y(PI/4), rotation_x(PI/2), scaling(10, 0.01, 10), NULL));
	set_material(&right_wall->shape, materialcpy(*m));

	middle = sphere();
	transform((void*)&middle->shape, translation(-0.5, 1, 0.5));
	t_material *m2 = default_material();
	set_material_color(m2, color(0.8, 0, 0));
	m2->diffuse = 0.7;
	m2->specular = 0.3;
	set_material(&middle->shape, m2);

	right = sphere();
	transform((void *)&right->shape, chain_tfs(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5), NULL));
	t_material *m3 = materialcpy(*m2);
	set_material_color(m3, color(0, 0, 0.8));
	set_material(&right->shape, m3);

	left = sphere();
	transform((void *)&left->shape, chain_tfs(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33), NULL));
	t_material *m4 = materialcpy(*m2);
	set_material_color(m4, color(1, 1, 0));
	set_material(&left->shape, m4);

	t_point_light *light = point_light(color(1, 1, 1), point(-10, 10, -10));
	t_camera *cam = camera(100, 50, PI/3);
	transform( (void*)cam, view_transformation(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0)));
	t_world *w = empty_world();
	set_light(w, light);
	set_shape(w, &floor->shape);
	set_shape(w,  &left_wall->shape);
	set_shape(w,  &right_wall->shape);
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


