/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiu <lchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:17:34 by shuppert          #+#    #+#             */
/*   Updated: 2024/05/23 13:22:13 by lchiu            ###   ########.fr       */
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
