/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:17:34 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 12:42:29 by lchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	fill_orientation(t_matrix *orientation, const t_tuple left,
		const t_tuple true_up, const t_tuple forward)
{
	orientation->m[0][0] = left.x;
	orientation->m[0][1] = left.y;
	orientation->m[0][2] = left.z;
	orientation->m[0][3] = 0.0;
	orientation->m[1][0] = true_up.x;
	orientation->m[1][1] = true_up.y;
	orientation->m[1][2] = true_up.z;
	orientation->m[1][3] = 0.0;
	orientation->m[2][0] = -forward.x;
	orientation->m[2][1] = -forward.y;
	orientation->m[2][2] = -forward.z;
	orientation->m[2][3] = 0.0;
	orientation->m[3][0] = 0.0;
	orientation->m[3][1] = 0.0;
	orientation->m[3][2] = 0.0;
	orientation->m[3][3] = 1.0;
}

t_matrix	*view_transformation(t_tuple *from, t_tuple *to, t_tuple *up)
{
	t_tuple		*forward;
	t_tuple		*upn;
	t_tuple		*left;
	t_tuple		*true_up;
	t_matrix	*m;

	if (!from || !to || !up || from->tf.type != POINT || to->tf.type != POINT
		|| up->tf.type != VECTOR)
	{
		printf("Error: view_transformation: invalid arguments.\n");
		return (identity(4));
	}
	forward = norm(sub_tuple(*to, *from));
	upn = norm(tuplecpy(*up));
	left = norm(cross(*forward, *upn));
	true_up = cross(*left, *forward);
	m = matrix(4, 4);
	fill_orientation(m, *left, *true_up, *forward);
	m = chain_tfs(m, translation(-from->x, -from->y, -from->z), NULL);
	free_tuples(&from, &to, &up, &forward, &upn, &left, &true_up, NULL);
	return (m);
}

t_camera	*camera(double hsize, double vsize, double field_of_view)
{
	t_camera	*cam;

	cam = (t_camera *)calloc(1, sizeof(t_camera));
	if (!cam)
	{
		printf("Error: camera: calloc failed.\n");
		return (NULL);
	}
	cam->hsize = hsize;
	cam->vsize = vsize;
	cam->field_of_view = field_of_view;
	pixel_size(cam);
	cam->vt = identity(4);
	cam->tf.type = CAMERA;
	cam->tf.transform = transform_camera;
	return (cam);
}

void	pixel_size(t_camera *cam)
{
	double	half_view;
	double	aspect;

	half_view = tan(cam->field_of_view / 2);
	aspect = cam->hsize / cam->vsize;
	if (aspect >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_height = half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
}

void	free_camera(t_camera **cam)
{
	free_matrix(&(*cam)->vt);
	free(*cam);
	*cam = NULL;
}

t_ray	*ray_for_pixel(t_camera *cam, double pixel_x, double pixel_y)
{
	t_ray			*r;
	t_tuple			*origin;
	t_tuple			*direction;
	t_tuple			*pixel;
	t_coordinates	world_cords;

	// Calculate the world coordinates of the pixel
	world_cords.x = cam->half_width - (pixel_x + 0.5) * cam->pixel_size;
	world_cords.y = cam->half_height - (pixel_y + 0.5) * cam->pixel_size;
	// Transform the pixel in world coordinates to camera coordinates
	pixel = point(world_cords.x, world_cords.y, -1);
	transform((void *)pixel, inverse(*cam->vt));
	// Create the ray: origin is the camera,
		direction is the normed vector from the camera to the pixel
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
	t_data *data;
	char *src;
	unsigned int _color;
	t_color *color;

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