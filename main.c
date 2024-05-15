#include "libs/librt.h"

int main(void)
{
	t_scene *_scene;

	_scene = scene();
	make_camera(point(-0.5, 0.6, -10), point(0, 0, 1), degrees_to_radians(40));
	make_ambient_light(0.2, color(1, 1, 1));
	make_light(point(-5, 5, -5), 0.9, color(1, 1, 1));
	make_plane(point(0, 0, 10), vector(-0.707107, 0, -0.707107), color(div_255(255), div_255(255), div_255(255)), NULL);
	make_plane(point(0, 0, 10), vector(0.707107, 0, -0.707107), color(div_255(255), div_255(255), div_255(255)), NULL);
	make_plane(point(0, -1, 0), norm(vector(0, 1, 0)), color(div_255(76.5), div_255(127), div_255(255)), rfl(0.3), NULL);
	make_sphere(point(-2, -0.5, 2), 1, color(div_255(255), div_255(51), div_255(51)), NULL);
	make_sphere(point(-0.5, 0, 3.5), 2, color(div_255(51), div_255(255), div_255(51)), NULL);
	make_sphere(point(-1, -0.6, 2), 0.8, color(div_255(255), div_255(255), div_255(51)), NULL);
	make_sphere(point(0.2, 0, -5), 2, color(div_255(0), div_255(0), div_255(105)), tsy(0.9), rfr(2.25), NULL);
	make_cylinder(point(1, -0.7, 0), vector(-0.196116, 0.980581, 0), 0.7, 1.5, color(div_255(255), div_255(0), div_255(127)), NULL);

	_scene->canvas = render(_scene->camera, _scene->world);
	set_events_and_display(_scene->canvas);
	return (0);
}

//int main(int ac, char **av)
//{
//	t_scene *_scene;
//	int   fd;
//
//	_scene = scene();
//
//    if (check_cmd_line(ac, av) == 1)
//        return (1);
//    fd = open(av[ac - 1], O_RDONLY);
//    if (fd == -1)
//    {
//        perror("fd");
//        close(fd);
//        return (1);
//    }
//    if (check_file_rt(fd) == 1)
//    {
//        close(fd);
//        return (1);
//    }
//    close(fd);
//    // (void)_scene;
//	_scene->canvas = render(_scene->camera, _scene->world);
//	set_events_and_display(_scene->canvas);
//    
//}