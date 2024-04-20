#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>


int main(void)
{
	{
		t_camera *cam;
		t_ray *ray;

		cam = camera(201, 101, PI / 2);
		ray = ray_for_pixel(cam, 100, 50);
		print_ray(ray);
		free_camera(&cam);
		free_ray(&ray);
	}
	{
		t_camera *cam;
		t_ray *ray;

		cam = camera(201, 101, PI / 2);
		ray = ray_for_pixel(cam, 0, 0);
		print_ray(ray);
		free_camera(&cam);
		free_ray(&ray);
	}
	{
		t_camera *cam;
		t_ray *ray;

		cam = camera(201, 101, PI / 2);
		
		ray = ray_for_pixel(cam, 100, 50);
		print_ray(ray);
		free_camera(&cam);
		free_ray(&ray);
	}

}

