#include "libs/librt.h"


int main(void)
{	
	t_world *w = empty_world();

	t_point_light *light = point_light(white(), point(-5, 5, -5));
	set_light(w, light);

	t_plane *waterSurface = plane();
	set_pattern(waterSurface->shape.material, solid(color(0.2, 0.6, 0.99)));
	set_diffuse(waterSurface->shape.material, 0.3);
	set_reflective(waterSurface->shape.material, 0.6);
	set_transparency(waterSurface->shape.material, 0.7);
	set_refrac_index(waterSurface->shape.material, 1.333);
	waterSurface->shape.can_cast_shadow = 0;
	set_shape(w, &waterSurface->shape);

	//t_plane *waterBed = plane();
	//set_pattern(waterBed->shape.material, solid(color(0.5, 0.25, 0.15)));
	//set_diffuse(waterBed->shape.material, 0.9);
	//set_reflective(waterBed->shape.material, 0.0);
	//set_transparency(waterBed->shape.material, 0.5);
	//set_specular(waterBed->shape.material, 0.0);
	//set_refrac_index(waterBed->shape.material, 1.00029);
	//transform(waterBed, translation(0, -5, 0));
	//set_shape(w, &waterBed->shape);

	t_sphere *_sphere = sphere();
	transform(_sphere, chain_tfs(translation(1, 0, -2), scaling(1.5, 1.5, 1.5), NULL));
	set_pattern(_sphere->shape.material, solid(white()));
	_sphere->shape.material->diffuse= 0.9;
    _sphere->shape.material->reflective = 0.5;
    _sphere->shape.material->transparency = 0.0;
    _sphere->shape.material->specular = 1.0;
	_sphere->shape.can_cast_shadow = 0;
    _sphere->shape.material->shininess = 300.0;
	set_shape(w, &_sphere->shape);

	t_sphere *_sphere2 = sphere();
	transform(_sphere2, chain_tfs(scaling(1.5, 1.5, 1.5), translation(-3, -5, 1), NULL));
	set_pattern(_sphere2->shape.material, solid(color(0.2, 0.1423, 0.5)));
	_sphere2->shape.material->diffuse= 0.9;
    _sphere2->shape.material->reflective = 0.5;
    _sphere2->shape.material->transparency = 0.8;
    _sphere2->shape.material->specular = 1.0;
	_sphere2->shape.can_cast_shadow = 0;
    _sphere2->shape.material->shininess = 300.0;
	set_shape(w, &_sphere2->shape);

	t_sphere *_sphere3 = sphere();
	transform(_sphere3, chain_tfs(translation(-1, -1, 6), NULL));
	set_pattern(_sphere3->shape.material, solid(color(0.337812, 0.552, 0.267)));
	_sphere3->shape.material->diffuse= 0.9;
    _sphere3->shape.material->reflective = 0.6;
    _sphere3->shape.material->transparency = 0.8;
    _sphere3->shape.material->specular = 1.0;
	_sphere3->shape.can_cast_shadow = 0;
    _sphere3->shape.material->shininess = 300.0;
	set_shape(w, &_sphere3->shape);

	t_sphere *_sphere4 = sphere();
	transform(_sphere4, chain_tfs(translation(-3.5, -2, 5), scaling(1.2, 1.2, 1.2), NULL));
	set_pattern(_sphere4->shape.material, solid(color(0.537812, 0.252, 0.367)));
	_sphere4->shape.material->diffuse= 0.9;
    _sphere4->shape.material->reflective = 0.6;
    _sphere4->shape.material->transparency = 0.8;
    _sphere4->shape.material->specular = 1.0;
	_sphere4->shape.can_cast_shadow = 0;
    _sphere4->shape.material->shininess = 300.0;
	set_shape(w, &_sphere4->shape);

	t_sphere *_sphere5 = sphere();
	transform(_sphere5, chain_tfs(translation(-3.5, 0, 7), scaling(1.5, 1.5, 1.5), NULL));
	set_pattern(_sphere5->shape.material, solid(color(0.3748, 0.3414, 0.567)));
	_sphere5->shape.material->diffuse= 0.9;
    _sphere5->shape.material->reflective = 0.6;
    _sphere5->shape.material->transparency = 0.0;
    _sphere5->shape.material->specular = 1.0;
	_sphere5->shape.can_cast_shadow = 0;
    _sphere5->shape.material->shininess = 200.0;
	set_shape(w, &_sphere5->shape);

	t_sphere *_sphere6 = sphere();
	transform(_sphere6, chain_tfs(scaling(1.5, 1.5, 1.5), translation(3, -5, 0), NULL));
	set_pattern(_sphere6->shape.material, solid(color(0.537812, 0.252, 0.367)));
	_sphere6->shape.material->diffuse= 0.9;
    _sphere6->shape.material->reflective = 0.5;
    _sphere6->shape.material->transparency = 0.8;
    _sphere6->shape.material->specular = 1.0;
	_sphere6->shape.can_cast_shadow = 0;
    _sphere6->shape.material->shininess = 300.0;
	set_shape(w, &_sphere6->shape);


	t_sphere *_sphere7 = sphere();
	transform(_sphere7, chain_tfs(scaling(1.1, 1.1, 1.1), translation(4, -1, 7), NULL));
	set_pattern(_sphere7->shape.material, solid(white()));
	_sphere7->shape.material->diffuse= 0.9;
    _sphere7->shape.material->reflective = 0.5;
    _sphere7->shape.material->transparency = 0.8;
    _sphere7->shape.material->specular = 1.0;
	_sphere7->shape.can_cast_shadow = 0;
    _sphere7->shape.material->shininess = 300.0;
	set_shape(w, &_sphere7->shape);

	t_sphere *_sphere8 = sphere();
	transform(_sphere8, chain_tfs(scaling(1.1, 1.1, 1.1), translation(3, -3, 4), NULL));
	set_pattern(_sphere8->shape.material, solid(color(0.337812, 0.552, 0.267)));
	_sphere8->shape.material->diffuse= 0.9;
    _sphere8->shape.material->reflective = 0.5;
    _sphere8->shape.material->transparency = 0.8;
    _sphere8->shape.material->specular = 1.0;
	_sphere8->shape.can_cast_shadow = 0;
    _sphere8->shape.material->shininess = 300.0;
	set_shape(w, &_sphere8->shape);

	t_sphere *_phere9 = sphere();
	transform(_phere9, chain_tfs(scaling(1.1, 1.1, 1.1), translation(-3, -8, 4), NULL));
	set_pattern(_phere9->shape.material, solid(color(0.337812, 0.552, 0.267)));
	_phere9->shape.material->diffuse= 0.9;
    _phere9->shape.material->reflective = 0.5;
    _phere9->shape.material->transparency = 0.8;
    _phere9->shape.material->specular = 1.0;
	_phere9->shape.can_cast_shadow = 0;
    _phere9->shape.material->shininess = 300.0;
	set_shape(w, &_phere9->shape);



	t_camera *cam = camera(100, 80, PI / 3.0);
	t_matrix *vt = view_transformation(point(0, 5, -10), point(0, -2, 4), vector(0, 1, 0));
	transform(cam, vt);



	t_canvas *canvas = render(cam, w);
	display_image(canvas);
	
}