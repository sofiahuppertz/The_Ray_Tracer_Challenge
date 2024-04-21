#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>


int main(void)
{	
	t_sphere *floor;
	t_sphere *left_wall;
	t_sphere *right_wall;
	t_sphere *middle;
	t_sphere *right;
	t_sphere *left;

	floor = sphere();
	set_transform(SPHERE, (void*)floor, scaling(10, 0.01, 10));
	t_material *m = default_material();
	set_material_color(m, color(1, 0.9, 0.9));
	m->specular = 0;
	set_material(floor, m);

	left_wall = sphere();
	set_transform(SPHERE, (void*)left_wall, chain_tfs(translation(0, 0, 5), rotation_y(-PI/4), rotation_x(PI/2), scaling(10, 0.01, 10), NULL));
	set_material(left_wall, materialcpy(*m));

	right_wall = sphere();
	set_transform(SPHERE, (void*)right_wall, chain_tfs(translation(0, 0, 5), rotation_y(PI/4), rotation_x(PI/2), scaling(10, 0.01, 10), NULL));
	set_material(right_wall, materialcpy(*m));

	middle = sphere();
	set_transform(SPHERE, (void*)middle, translation(-0.5, 1, 0.5));
	t_material *m2 = default_material();
	set_material_color(m2, color(0.1, 1, 0.5));
	m2->diffuse = 0.7;
	m2->specular = 0.3;
	set_material(middle, m2);

	right = sphere();
	set_transform(SPHERE, (void*)right, chain_tfs(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5), NULL));
	t_material *m3 = materialcpy(*m2);
	set_material_color(m3, color(0.5, 1, 0.1));
	set_material(right, m3);

	left = sphere();
	set_transform(SPHERE, (void*)left, chain_tfs(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33), NULL));
	t_material *m4 = materialcpy(*m2);
	set_material_color(m4, color(1, 0.8, 0.1));
	set_material(left, m4);

	t_point_light *light = point_light(color(1, 1, 1), point(-10, 10, -10));
	t_camera *cam = camera(100, 50, PI/3);
	set_transform(CAMERA, (void*)cam, view_transformation(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0)));
	t_world *w = empty_world();
	set_light(w, light);
	add_sphere_to_world(w, floor);
	add_sphere_to_world(w, left_wall);
	add_sphere_to_world(w, right_wall);
	add_sphere_to_world(w, middle);
	add_sphere_to_world(w, right);
	add_sphere_to_world(w, left);

	t_canvas *canvas = render(cam, w);
	display_image(canvas);

	free_camera(&cam);
	free_world(&w);
	free(canvas);


}


