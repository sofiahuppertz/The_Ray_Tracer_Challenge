/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:21:59 by lchiu             #+#    #+#             */
/*   Updated: 2024/05/23 13:25:11 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

// Calculate the world coordinates of the pixel l.118/119
// Transform the pixel in world coordinates to camera coordinates l.121/122
// Create the ray: origin is the camera, direction is the normed vector from
// the camera to the pixel l.124
t_ray	*ray_for_pixel(t_camera *cam, double pixel_x, double pixel_y)
{
	t_ray			*r;
	t_tuple			*origin;
	t_tuple			*direction;
	t_tuple			*pixel;
	t_coordinates	world_cords;

	world_cords.x = cam->half_width - (pixel_x + 0.5) * cam->pixel_size;
	world_cords.y = cam->half_height - (pixel_y + 0.5) * cam->pixel_size;
	pixel = point(world_cords.x, world_cords.y, -1);
	transform((void *)pixel, inverse(*cam->vt));
	origin = point(0, 0, 0);
	transform((void *)origin, inverse(*cam->vt));
	direction = sub_tuple(*pixel, *origin);
	r = ray(origin, direction);
	free(pixel);
	return (r);
}

void	transform_camera(void *cam, t_matrix *vt)
{
	t_camera	*c;

	c = (t_camera *)cam;
	if (c->vt)
		free_matrix(&c->vt);
	c->vt = vt;
}

t_canvas	*render(t_camera *cam, t_world *w)
{
	t_canvas		*_canvas;
	t_color			*color;
	t_coordinates	coord;
	t_ray			*ray;

	_canvas = canvas((int)cam->hsize, (int)cam->vsize);
	coord.y = 0;
	while (coord.y < cam->vsize - 1)
	{
		coord.x = 0;
		while (coord.x < cam->hsize - 1)
		{
			ray = ray_for_pixel(cam, (double)coord.x, (double)coord.y);
			color = color_at(*w, *ray, 5);
			draw_pixel(&_canvas->img, (int)coord.x, (int)coord.y, color);
			coord.x++;
			free_ray(&ray);
			free(color);
		}
		coord.y++;
	}
	return (_canvas);
}

void	print_camera(const t_camera *cam)
{
	printf("Camera:\n");
	printf("hsize: %f\n", cam->hsize);
	printf("vsize: %f\n", cam->vsize);
	printf("half_width: %f\n", cam->half_width);
	printf("half_height: %f\n", cam->half_height);
	printf("field_of_view: %f\n", cam->field_of_view);
	printf("pixel_size: %f\n", cam->pixel_size);
	print_matrix(cam->vt);
}

t_color	*pixel_at(t_canvas *c, int x, int y)
{
	t_data			*data;
	char			*src;
	unsigned int	_color;
	t_color			*color;

	color = NULL;
	color = (t_color *)calloc(1, sizeof(t_color));
	if (!color)
	{
		printf("Error: pixel_at: calloc failed.\n");
		return (color);
	}
	data = &c->img;
	src = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	_color = *(unsigned int *)src;
	color->b = (_color & 0xFF) / 255.0;
	color->g = ((_color >> 8) & 0xFF) / 255.0;
	color->r = ((_color >> 16) & 0xFF) / 255.0;
	(void)x;
	(void)y;
	return (color);
}
