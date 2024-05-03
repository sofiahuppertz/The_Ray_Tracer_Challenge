
int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(point(0, 0.6, -5), point(0, 0.5, 1), degrees_to_radians(40));
	make_ambient_light(0.2, color(1, 1, 1));
	make_light(point(-5, 5, -5), 0.9, color(1, 1, 1));
	//make_plane(point(0, 1.4, 0), norm(vector(0, 1, 0)), color(div_255(0), div_255(0), div_255(0)), rfl(1.0), NULL);
	//_scene->world->shapes->can_cast_shadow = 0;
	make_plane(point(0, -1.2, 0), norm(vector(0, 1, 0)), color(div_255(255), div_255(255), div_255(255)), rfl(0.7), NULL);
	make_plane(point(0, 0, 4), norm(vector(0, 0, 1)), color(div_255(255), div_255(255), div_255(255)), NULL);
	make_cone(point(0, 0, 1), vector(0, 1, 0), 0.5, 2.5, color(div_255(255), div_255(0), div_255(127)), stripe(white(), color(div_255(255), div_255(154), div_255(0)), 0.7, 90), NULL);
	make_cylinder(point(0, -1.2, 1), vector(0, 1, 0), 1.6, 0.1, color(div_255(255), div_255(154), div_255(0)), NULL);
	_scene->canvas = render(_scene->camera, _scene->world);
	display_image(_scene->canvas);
}