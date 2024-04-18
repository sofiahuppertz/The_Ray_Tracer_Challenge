#include "minilibx/mlx.h"
#include "libs/librt.h"
#include <stdio.h>

#define PI 3.14159265358979323846




int main(void)
{
	t_space space;

	space.view_point = point(0, 0, -5);
	space.wall_z = 10.0;
	space.wall_size = 7.0;
	space.half = space.wall_size / 2.0;
	space.light = point_light(color(1, 1, 1), point(0, 10, -10));

	t_canvas *_canvas = canvas(CANVAS_PIXELS, CANVAS_PIXELS, space.wall_size);
	
	t_sphere *sp = sphere();
	set_material_color(sp->material, color(0.2, 0.6, 1));
	print_sphere(sp);

	draw_sphere(space, _canvas, *sp);
	printf("drawn\n");
	mlx_put_image_to_window(_canvas->mlx, _canvas->mlx_win, _canvas->img.img, 0, 0);
	mlx_loop(_canvas->mlx);
	return 0;
}

//int main(void){
//	
//	t_tuple *ray_origin = point(0, 0, -5);
//	double wall_z = 10.0;
//	double wall_size = 7.0;
//	double pixel_size = wall_size / canvas_pixels;
//	double half = wall_size  / 2;
//
//	t_canvas *_canvas = canvas((int)canvas_pixels, (int)canvas_pixels);
//	
//	t_color *_color;
//	t_sphere *shape = sphere();
//	set_material_color(shape->material, color(0.2, 0.6, 1));
//	print_sphere((const t_sphere *)shape);
//
//	t_point_light *light = point_light(color(1, 1, 1), point(0, 10, -10));
//
//	for (int y= 0; y < canvas_pixels -1 ; y++)
//	{
//		double world_y = half - pixel_size * y;
//
//		for (int x = 0; x < canvas_pixels -1; x++)
//		{
//			double world_x = -half + pixel_size * x;
//			t_tuple *position = point(world_x, world_y, wall_z);
//			t_tuple *temp = sub_tuple((const t_tuple)*position, (const t_tuple)*ray_origin);
//			norm(temp);
//			t_ray *r = ray((const t_tuple)*ray_origin, (const t_tuple)*temp);
//			t_intersection *xs = i_ray_sphere((const t_sphere)*shape, (const t_ray)*r);
//			t_intersection *_hit = hit(&xs);
//			if (_hit)
//			{
//				t_tuple *hit_pos = position_at(_hit->t, (const t_ray)*r);
//				t_tuple *normal = normal_at((const t_sphere)*shape, (const t_tuple)*hit_pos);
//				t_tuple *eye = tuplecpy((const t_tuple)(*r->di));
//				neg_tuple(eye);
//				_color = lighting((const t_material)*shape->material, (const t_point_light)*light, (const t_tuple)*hit_pos, (const t_tuple)*eye, (const t_tuple)*normal);
//				draw_pixel(&(_canvas->img), x, y, (const t_color *)_color);
//				free(hit_pos);
//			}
//			free(temp);
//			free(position);
//			free_intersections(&xs);
//			free_ray(&r);
//		}
//	}
//	mlx_put_image_to_window(_canvas->mlx, _canvas->mlx_win, _canvas->img.img, 0, 0);
//	mlx_loop(_canvas->mlx);
//}