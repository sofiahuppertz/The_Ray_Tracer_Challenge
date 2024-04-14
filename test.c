#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>

int canvas_pixels = 200;

int main(void){
	
	t_tuple *ray_origin = point(0, 0, -5);
	double wall_z = 10.0;
	double wall_size = 7.0;
	double pixel_size = wall_size / canvas_pixels;
	double half = wall_size  / 2;

	t_canvas *_canvas = canvas((int)canvas_pixels, (int)canvas_pixels);
	
	t_color *_color= color(255, 255, 255);
	t_sphere *shape = sphere();

	for (int y= 0; y < canvas_pixels -1 ; y++)
	{
		double world_y = half - pixel_size * y;

		for (int x = 0; x < canvas_pixels -1; x++)
		{
			double world_x = -half + pixel_size * x;
			t_tuple *position = point(world_x, world_y, wall_z);
			t_tuple *temp = sub_tuple((const t_tuple)*position, (const t_tuple)*ray_origin);
			t_tuple *temp2 = norm((const t_tuple)*temp);
			t_ray *r = ray((const t_tuple)*ray_origin, (const t_tuple)*temp2);
			t_intersection *xs = i_ray_sphere((const t_sphere)*shape, (const t_ray)*r);
			t_intersection *_hit = hit(&xs);

			if (_hit)
			{
				draw_pixel(&(_canvas->img), x, y, (const t_color *)_color);
			}
			free(temp);
			free(temp2);
			free(position);
			free_intersections(&xs);
			free_ray(&r);
		}
	}
	mlx_put_image_to_window(_canvas->mlx, _canvas->mlx_win, _canvas->img.img, 0, 0);
	mlx_loop(_canvas->mlx);
}

